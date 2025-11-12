#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	cin>>a;
	for(unsigned long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b.push_back(a[i]);
		}
	}
	sort(b.begin(),b.end(),greater<unsigned long long>() );
	cout<<b;
	return 0;
}

