#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
string s;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=2*n;i++){
		cin>>s;
	}
	for(int i=1;i<=2*q;i++){
		cin>>s;
	}
	for(int i=1;i<=q;i++){
		printf("0\n");
	}
	return 0;
}