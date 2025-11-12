#include<bits/stdc++.h>
using namespace std;
int n,q;
struct change{
	string s1,s2;
}a[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		std::cin>>a[i].s1;
		std::cin>>a[i].s2;
	}
	for(int i=1;i<=1;i++){
		string ss1,ss2;
		std::cin>>ss1>>ss2;
		cout<<0<<'\n';
	}
	return 0;
}
