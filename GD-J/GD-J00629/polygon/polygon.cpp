#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans;
vector<long long>vec;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	vec.push_back(a[1]+a[2]);
	for(int i=3;i<=n;i++){
		long long num=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
		if(num!=vec.size())
		ans=(ans+vec.size()-num )%mod;
		vector<long long>vec1=vec;
		for(int j=0;j<vec1.size();j++)
		vec.push_back(vec1[j]+a[i]);
		for(int j=1;j<i;j++)
		vec.push_back(a[j]+a[i]);
		sort(vec.begin(),vec.end());
	}
	cout<<ans;
	return 0;
}
