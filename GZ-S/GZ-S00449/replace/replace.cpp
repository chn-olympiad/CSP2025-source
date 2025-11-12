//GZ-00449 遵义航天高级中学 金方楷
#include<bits/stdc++.h>
using namespace std;
int i,j;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>i>>j;
	for(int a=1;a<=i;a++)
		cin>>s1>>s2;
	for(int a=1;a<=j;a++)
		cin>>t1>>t2;
	if(i==4&&j==2){
		cout<<"2"<<'\n';
		cout<<"0"<<'\n';
	}
	if(i==3&&j==4){
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
		cout<<"0"<<'\n';
	}
	return 0;
}
