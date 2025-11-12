#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define uLL unsigned long long

using namespace std;

const int N=2e5+5,L=5e6+5;

int n,Q,tmp;
char ch[L];
vector<char>s[N][2],t[N][2];

namespace BF{
	const int P=131;
	uLL p[L];
	uLL a[N],now1,now2;
	const int H=1e7+9;
	int bz[H];uLL id[H];
	int Hash(uLL x){
		int y=x%H;
		while(bz[y]!=0&&id[y]!=x)y=(y+1)%H;
		return y;
	}
	int Ans,he,ed;
	void Solve(vector<char>s1,vector<char>s2){
		tmp=s1.size();
		if(tmp!=(int)s2.size()){
			printf("0\n");
			return;
		}
		Ans=0;
		he=0;
		while(s1[he]==s2[he])he++;
		ed=tmp-1;
		while(s1[ed]==s2[ed])ed--;
		for(int i=0;i<=he;i++){
			now1=0;now2=0;
			for(int j=i;j<tmp;j++){
				now1=now1*P+(int)(s1[j]-'a'+1);
				now2=now2*P+(int)(s2[j]-'a'+1);
				if(j<ed)continue;
				int x=Hash(now1*p[j-i+1]+now2);
				Ans+=bz[x];
			}
		}
		printf("%d\n",Ans);
		return;
	}
	void solve(){
		p[0]=1;
		for(int i=1;i<=5000000;i++)p[i]=p[i-1]*P;
		for(int i=1;i<=n;i++){
			for(int j=0;j<2;j++){
				tmp=s[i][j].size();
				for(int k=0;k<tmp;k++){
					a[i]=a[i]*P+(int)(s[i][j][k]-'a'+1);
				}
			}
			tmp=Hash(a[i]);
			bz[tmp]++;id[tmp]=a[i];
		}
		for(int i=1;i<=Q;i++){
			Solve(t[i][0],t[i][1]);
		}
		return;
	}
}

namespace subB{
	struct Node{int ai,bi,id;};
	bool cmp1(Node x,Node y){
		return x.ai<y.ai;
	}
	vector<Node>a[L*2],q[L*2];
	int now1,now2,Ans[N];
	bool ck(){
		for(int i=1;i<=n;i++){
			now1=now2=-1;
			for(int j=0;j<(int)s[i][0].size();j++){
				if(s[i][0][j]=='b'){
					if(now1!=-1)return 0;
					now1=j;
				}
				else if(s[i][0][j]!='a')return 0;
				if(s[i][1][j]=='b'){
					if(now2!=-1)return 0;
					now2=j;
				}
				else if(s[i][1][j]!='a')return 0;
			}
			if(now1==-1||now2==-1)return 0;
			a[now1-now2+L].push_back({now1-1,(int)(s[i][0].size())-now1,0});
		}
		for(int i=1;i<=Q;i++){
			now1=now2=-1;
			for(int j=0;j<(int)t[i][0].size();j++){
				if(t[i][0][j]=='b'){
					if(now1!=-1)return 0;
					now1=j;
				}
				else if(t[i][0][j]!='a')return 0;
				if(t[i][1][j]=='b'){
					if(now2!=-1)return 0;
					now2=j;
				}
				else if(t[i][1][j]!='a')return 0;
			}
			if(now1==-1||now2==-1)return 0;
			q[now1-now2+L].push_back({now1-1,(int)(t[i][0].size())-now1,i});
		}
		return 1;
	}
	int tr[L*2];
	int lowbit(int x){return x&(-x);}
	void put(int x,int s){x+=10;while(x<L*2)tr[x]+=s,x+=lowbit(x);return;}
	int get(int x){x+=10;int s=0;while(x>0)s+=tr[x],x-=lowbit(x);return s;}
	void calc(vector<Node>A,vector<Node>B){
		sort(A.begin(),A.end(),cmp1);
		sort(B.begin(),B.end(),cmp1);
		tmp=0;
		for(int i=0;i<(int)B.size();i++){
			while(tmp<(int)A.size()&&A[tmp].ai<=B[i].ai){
				put(A[tmp].bi,1);
				tmp++;
			}
			Ans[B[i].id]=get(B[i].bi);
		}
		for(int i=0;i<tmp;i++){
			put(A[i].bi,-1);
		}
		return;
	}
	void solve(){
		for(int i=0;i<L*2;i++)calc(a[i],q[i]);
		for(int i=1;i<=Q;i++)printf("%d\n",Ans[i]);
		return;
	}
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			scanf("%s",ch);tmp=strlen(ch);
			s[i][j]=vector<char>(tmp);
			for(int k=0;k<tmp;k++){
				s[i][j][k]=ch[k];
			}
		}
	}
	for(int i=1;i<=Q;i++){
		for(int j=0;j<2;j++){
			scanf("%s",ch);tmp=strlen(ch);
			t[i][j]=vector<char>(tmp);
			for(int k=0;k<tmp;k++){
				t[i][j][k]=ch[k];
			}
		}
	}
	
	if(subB::ck())subB::solve();
	else BF::solve();
	
	return 0;
}
