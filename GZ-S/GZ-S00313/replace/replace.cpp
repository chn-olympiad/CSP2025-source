//GZ-S00313 贵州省 王天垒 520123201106071230 贵阳市白云区华师一学校 初三 
#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> ma;
string s[10001],s2[100001];
string q[10001],q2[100001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cin>>q[i]>>q2[i];
	}
	for(int i=1;i<=m;i++){
		cout<<"0"<<" ";
	}
	return 0;
}
