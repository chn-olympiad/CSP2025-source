#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
map<int,bool> mp;
int s[N],a[N],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
//	cout<<(0^0)<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
//		if(a[i]==0&&a[i-1]==0&&i!=1){
//			s[i]=s[i]^1;
//		}
		// cout<<s[i]<<' ';
	}
	// int ans=0;
//	mp[0]=1;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
//		cout<<mp[0]<<' '<<endl; 
		if(mp[k^s[i]]||(s[i]^s[i-1])==k){
			mp.clear();
			ans++;
			if(a[i]==1)sum1++;
			else sum2++;
			// cout<<i<<' '<<a[i]<<'\n';
//			mp[0]=1;
		}
		else{
			mp[s[i-1]]=1;
		}
	}
	// cout<<sum1<<' '<<sum2<<endl;
	cout<<ans;
}
