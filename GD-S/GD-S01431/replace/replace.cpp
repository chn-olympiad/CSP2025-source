#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q;
const ll mod=998244353,p=13331,ba=131;
const int N=2e5+5;
string a[N],b[N];
int la[N],lb[N];
ll ha[N],hb[N];
int sum[N];
int di[N];
ll haxi(string s){
	ll res=0;
	for(int i=0;i<s.size();i++){
		res=(res*ba+s[i])*p%mod;
	}
	//cout<<s<<' '<<res<<endl;
	return res;
}
//char s[N];
int main(){
	//ios::sync_stdio_with(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		la[i]=a[i].size()-1;lb[i]=b[i].size()-1;
		ha[i]=haxi(a[i]);hb[i]=haxi(b[i]);
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<l1;i++){
			if(s1[i]!=s2[i])di[i]=1;
			else di[i]=0;
			if(i==0)sum[i]=di[i];
			else sum[i]=sum[i-1]+di[i];
			//cout<<sum[i]<<' ';
		}
		for(int i=1;i<=n;i++){
			//int k=0;
			for(int j=0;j+la[i]<l1;j++){
				int f=0;
				if(sum[j+la[i]]-sum[max(j-1,0)]==sum[l1-1])f=1;
				if(haxi(s1.substr(j,la[i]+1))==ha[i]&&haxi(s2.substr(j,lb[i]+1))==hb[i]){
					//cout<<di[i]<<endl;
				    //cout<<i<<' '<<1<<endl;
					ans+=f;
				}
			}
		}
		printf("%d\n",ans);
		
	//	printf("%s %s")
	}
	return 0;
}
