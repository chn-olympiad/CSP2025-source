#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],f[500005];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			s[i]=a[i];
		}
		else{
			s[i]=s[i-1]^a[i];
		}
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		int rest=k^s[i];
		if(mp.count(rest)){
			f[i]=max(f[i],mp[rest]+1);
		}
		mp[s[i]]=f[i];
		//cout<<i<<" "<<f[i]<<endl;
	}
	cout<<f[n];
	return 0;
}
