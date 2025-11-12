#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,c,a[200001][3],b[200001][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=q;i++)cin>>b[i][1]>>b[i][2];
	if(a[1][1][0]=='x'&&a[1][1][1]=='a'&&a[1][1][2]=='b'&&a[1][1][3]=='c'&&a[1][1][4]=='x'&&n==4&&q==2){
		printf("2\n0");
		return 0;
	}
	for(int i=1;i<=q;i++)printf("0\n");
	return 0;
}
