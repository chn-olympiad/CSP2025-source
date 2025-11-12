#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[114514*2];
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string in1,in2;
	for(int i=1;i<=n;i++){
		cin>>in1>>in2;
		mp[in1]=in2;
		a[i]=in1;
	}
	for(int i=1,ans;i<=q;i++){
		ans=0;
		cin>>in1>>in2;
		if(in1.size()!=in2.size()){
			cout<<"0\n";
			continue;
		}
	}
	return 0;
}
//freopen("Replace.in","r",stdin);
//freopen("repalce.out","w",stdout);
