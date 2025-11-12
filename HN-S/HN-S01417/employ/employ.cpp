#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=988244353;
int n,m,ans,head;
string s;
int a[1005];
int mm[1005];
int num[1005];
struct nd{
	int pos;
	int last,next;
}aa[1005];
void dfs(int k){
	if(k==n+1){
		int as=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0')continue;
			if(mm[a[num[i]]]>=i)as++;
		}
		if(as>=m)ans=(ans+1)%mod;
	}
	for(int p=head;p;p=aa[p].next){
		if(head==p)head=aa[p].next;
		aa[aa[p].next].last=aa[p].last;
		aa[aa[p].last].next=aa[p].next;
		num[k]=aa[p].pos;
		aa[0]=(nd){0,0,0};
		dfs(k+1);
		aa[aa[p].next].last=p;
		aa[aa[p].last].next=p;
		num[k]=0;
		if(head==aa[p].next)head=p;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]=(nd){i,i-1,i+1};
		int ct=0;
		bool f=0;
		for(int j=0;j<n;j++){
			if(s[j]=='0')ct++;
			if(ct==a[i]){
				mm[a[i]]=j;
				f=1;
				break;
			}
		}
		if(!f)mm[a[i]]=n;
	}
	aa[1].last=0;
	aa[n].next=0;
	int ct=0;
	for(int i=0;i<s.size();i++)
		ct+=s[i]-'0';
	if(ct<m){
		cout<<0;
		return 0;
	}
	if(ct==n){
		int sum=1;
		for(int i=1;i<=n;i++)
			sum=(sum*i)%mod;
		cout<<sum%mod;
		return 0;
	}
	head=1;
	dfs(1);
	cout<<ans%mod;
	return 0;
}
