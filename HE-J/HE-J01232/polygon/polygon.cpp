#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
vector<int> a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	if(a[0]==n){
		ans=n+1;
	}else{
		ans=n*2-1;
	}
	cout<<ans;
	return 0;
}
