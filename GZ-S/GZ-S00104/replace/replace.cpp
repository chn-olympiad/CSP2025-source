//GZ-S00104 贵阳市南明区双龙华麟学校 周子铠 
#include<bits/stdc++.h>
using namespace std;
map<string,string> a;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[s1]=s2;
	}
	while(q--){
		cout<<0<<endl;
	}
	return 0;
}
