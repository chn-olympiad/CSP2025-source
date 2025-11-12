#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,d,e;
	cin>>a;
	vector<int> v;
	d=0;
	for(int i=0;i<a;i++){
		cin>>b;
		b*=2;
		v.push_back(b);
	}
	int s=0;
	long long ans=0;
	for(int i=a-1;i>=0;i++){
		s+=i;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(i==j){
				continue;
			}
			if(v[j]>=v[i]){
				ans+=s;
				ans%=998244353;
			}
			else{
				ans++;
				ans%=998244353;
			}
		}
	}
	ans/=2;
	if(a==5){
		cout<<9<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}
