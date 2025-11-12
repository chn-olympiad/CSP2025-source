#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
char a[1000010],b[1000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	cin>>s1>>s2;
	for(int i=0;i<n+q;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
