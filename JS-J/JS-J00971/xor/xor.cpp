#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	set<int> s;
	int a,b,c;
	cin>>a>>b;
	int ans=0;
	vector<int> v,n;
	for(int i=0;i<a;i++){
		cin>>c;
		v.push_back(c);
	}
	if(b==0){
		for(int i=0;i<a;i++){
			if(v[i]==0){
				ans++;
			}
		}
		for(int i=0;i<a-1;i++){
			if(v[i]==v[i+1]&&v[i]!=0){
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	int sum=0;
	for(int i=0;i<a;i++){
		n.push_back(v[i]);
		sum++;
		for(int j=i+1;j<a;j++){
			n.push_back(n[sum-1]^v[j]);
			sum++;
		}
	}
	for(int i=0;i<n.size();i++){
		if(n[i]==b){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
