#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	char c=getchar();int f=1;
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-f,c=getchar();
	x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
const int N=5e6+5;
const int M=5e6;
#define ull unsigned long long
const int H=998244353;
const int S2=1e9+7;
const int S3=131;
ull pw[N];
#define pr pair<ull,ull>
#define mp make_pair
char s1[N],s2[N];
int n,q,cnt=0;
struct node{
	int len;pr p;
	bool operator ==(node &e)const{
		if(len==e.len&&p==e.p)return 1;
		return 0;
	}
};
map<long long,int>MAP;
struct Node{
	int len,l,r;
	pr p1,p2;
};
vector<Node>v[N];
pr get(int l,int r){
	ull S1=0,S2=0;
	for(int i=l;i<=r;i++){
		S1+=pw[i-l]*(s1[i]-'a');
		S2+=pw[i-l]*(s2[i]-'a');
	}
	return mp(S1,S2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=M;i++)pw[i]=pw[i-1]*H;
	in(n);in(q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s1+1,s2+1);
		int len=strlen(s1+1);
		int fir=-1,last=-1;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j]){
				if(fir==-1)fir=j;
				last=j;
			}
		}
		Node s;node SS;
		SS.len=s.len=last-fir+1;
		pr p1=get(fir,last);
		SS.p=s.p1=p1;
		s.l=fir-1,s.r=len-last;
		s.p2=get(1,len);
		long long gg=SS.len*S2+SS.p.first+SS.p.second*S3;
		if(!MAP.count(gg)){cnt++;MAP[gg]=cnt;}
		v[MAP[gg]].push_back(s);	
	}
	while(q--){
		scanf("%s %s",s1+1,s2+1);
		int len=strlen(s1+1);
		int fir=-1,last=-1;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j]){
				if(fir==-1)fir=j;
				last=j;
			}
		}
		node s;
		s.len=last-fir+1;
		s.p=get(fir,last);
		long long gg=s.len*S2+s.p.first+s.p.second*S3;
		if(!MAP.count(gg)){
			printf("0\n");
			continue;
		}
		else{
			int id=MAP[gg],ans=0;
			for(auto tp:v[id]){
				int L=fir-tp.l,R=last+tp.r;
				if(L<1||R>len)continue;
				pr ck=get(L,R);
				if(ck==tp.p2)ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}