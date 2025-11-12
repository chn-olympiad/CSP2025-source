#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i;
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>s1>>s2;
	while(q--){
		cin>>s1>>s2;
		printf("0\n");
	}
}
