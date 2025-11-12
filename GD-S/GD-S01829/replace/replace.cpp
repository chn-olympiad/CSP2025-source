#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,maxl=5e6+5,L=5e6;
const ll BS=67,mod=1e9+7;

struct NODE{ string s,s2; int x,y; }a[maxn];
void Get_(string s,string s2,int id){
	int len=s.size(); int l=len;
	for(int i=0;i<len;i++)
		if(s[i]!=s2[i]){
			l=i;
			break;
		}
	int r=-1;
	for(int i=len-1;i>=0;i--)
		if(s[i]!=s2[i]){
			r=i;
			break;
		}
	a[id].x=l,a[id].y=r;
}

ll pw_[maxl];
bool Get_hs(string s,string st,int l,int r,ll *hs){
	if(l<0||r>=st.size()) return false;
	ll tmp=0;
	if(!l) tmp=hs[r];
	else tmp=(hs[r]-hs[l-1]*pw_[r-l+1]%mod+mod)%mod;
	ll tmp2=0;
	for(int i=0,len=s.size();i<len;i++)
		(tmp2*=BS)%=mod,(tmp2+=(s[i]-'a'+1))%=mod;
	return (tmp==tmp2);
}

int n;
ll hs[maxl],hs2[maxl];
void Get2_(string st,string st2){
	int len=st.size(),l=len;
	for(int i=0;i<len;i++)
		if(st[i]!=st2[i]){
			l=i;
			break;
		}
	int r=-1;
	for(int i=len-1;i>=0;i--)
		if(st[i]!=st2[i]){
			r=i;
			break;
		}
	hs[0]=st[0]-'a'+1;
	for(int i=1;i<len;i++)
		hs[i]=hs[i-1]*BS%mod+st[i]-'a'+1;
	hs2[0]=st2[0]-'a'+1;
	for(int i=1;i<len;i++)
		hs2[i]=hs2[i-1]*BS%mod+st2[i]-'a'+1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>a[i].y) continue;
		if(a[i].y-a[i].x+1==r-l+1){
			if(Get_hs(a[i].s,st,l-a[i].x,r+(a[i].s.size()-1-a[i].y),hs)&&Get_hs(a[i].s2,st2,l-a[i].x,r+(a[i].s2.size()-1-a[i].y),hs2)) cnt++;
		}
	}
	printf("%d\n",cnt);
	return;
}

string st,st2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw_[0]=1;
	for(int i=1;i<=L;i++)
		pw_[i]=pw_[i-1]*BS%mod;
	int q; scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].s2;
		Get_(a[i].s,a[i].s2,i);
	}
	while(q--){
		cin>>st>>st2;
		if(st.size()!=st2.size()){
			printf("0\n");
			continue;
		}
		Get2_(st,st2);
	}
	return 0;
}
