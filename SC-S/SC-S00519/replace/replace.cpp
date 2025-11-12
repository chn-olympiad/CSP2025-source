#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 5000005

int n,q;
string t[MAXN][3];
string s[MAXN][3];

int pi[MAXN];
bool ok[MAXN][3];

void KMP(string str,int id,int len){
	pi[1]=0;
	for(int i=2;i<str.size();i++){
		int j=pi[i-1];
		while(j&&str[j+1]!=str[i]) j=pi[j-1];
		if(str[j+1]==str[i]) ++j;
		pi[i]=j;
		if(pi[i]==len) ok[i-len-1][id]=true;
	}
}

int L1,L2;

void subtask1(){//L1,L2<=2000
	for(int i=1;i<=q;i++){
		int ans=0;
		int pre=0,suf=0;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]==s[i][2][j]) pre++;
			else break;
		}
		for(int j=s[i][1].size()-1;i>=0;j--){
			if(s[i][1][j]==s[i][2][j]) suf++;
			else break;
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=s[i][1].size();k++) ok[k][1]=ok[k][2]=false;
			KMP('#'+t[j][1]+'#'+s[i][1],1,t[j][1].size());
			KMP('#'+t[j][2]+'#'+s[i][2],2,t[j][2].size());
			for(int k=1;k<=s[i][1].size();k++){
				if(!(ok[k][1]&ok[k][2])) continue;
				if(s[i][1].size()-k>suf) continue;
				if(k-t[j][1].size()>pre) continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}

int tot;

struct node{
	int a,b,c;
	int id;
}no[MAXN];

bool cmpa(node &x,node &y) {return x.a<y.a||x.a==y.a&&x.id<y.id;}
bool cmpb(node &x,node &y) {return x.b<y.b||x.b==y.b&&x.id<y.id;}

int cnt[10000005];
int ans[MAXN];

void CDQ(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	sort(no+l,no+mid+1,cmpb);
	sort(no+mid+1,no+r+1,cmpb);
	int i=l,j=mid+1;
	while(j<=r){
		while(i<=mid&&no[i].b<=no[j].b){
			if(!no[i].id) cnt[no[i].c+5000000]++;
			i++;
		}
		if(no[j].id) ans[no[j].id]+=cnt[no[j].c+5000000];
		j++;
	}
	for(int k=l;k<i;k++){
		if(!no[k].id) cnt[no[k].c+5000000]--;
	}
}

void subtask2(){//B
	for(int i=1;i<=n;i++){
		int app1=0,app2=0;
		int pre=0,suf=0;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]=='b'){
				app1=j;
				pre=j;
				suf=t[i][1].size()-pre-1;
				break;
			}
		}
		for(int j=0;j<t[i][2].size();j++){
			if(t[i][2][j]=='b'){
				app2=j;
				break;
			}
		}
		no[++tot]={pre,suf,app1-app2,0};
	}
	for(int i=1;i<=q;i++){
		int app1=0,app2=0;
		int pre=0,suf=0;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='b'){
				app1=j;
				pre=j;
				suf=s[i][1].size()-pre-1;
				break;
			}
		}
		for(int j=0;j<s[i][2].size();j++){
			if(s[i][2][j]=='b'){
				app2=j;
				break;
			}
		}
		no[++tot]={pre,suf,app1-app2,i};
	}
	sort(no+1,no+tot+1,cmpa);
	CDQ(1,tot);
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++){
		cin>>t[i][1]>>t[i][2];
		L1+=t[i][1].size()+t[i][2].size();
		int tot=0;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!='a'&&t[i][1][j]!='b') flag1=false;
			else if(t[i][1][j]=='b') tot++;
		}
		if(tot!=1) flag2=false;
		tot=0;
		for(int j=0;j<t[i][2].size();j++){
			if(t[i][2][j]!='a'&&t[i][2][j]!='b') flag1=false;
			else if(t[i][2][j]=='b') tot++;
		}
		if(tot!=1) flag2=false;
	}
	for(int i=1;i<=q;i++){
		cin>>s[i][1]>>s[i][2];
		L2+=s[i][1].size()+s[i][2].size();
		int tot=0;
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]!='a'&&s[i][1][j]!='b') flag1=false;
			else if(s[i][1][j]=='b') tot++;
		}
		if(tot!=1) flag2=false;
		tot=0;
		for(int j=0;j<s[i][2].size();j++){
			if(s[i][2][j]!='a'&&s[i][2][j]!='b') flag1=false;
			else if(s[i][2][j]=='b') tot++;
		}
		if(tot!=1) flag2=false;
	}
	if(flag1&&flag2) subtask2();
	else subtask1();
	return 0;
}