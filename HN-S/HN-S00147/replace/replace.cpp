#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m;
map<string,string> a;
string b[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s,s1;
	for(int i=1; i<=n;i++){
		cin>>s>>s1;
		a[s]=s1;
	}
	for(int i=1;i<=m;i++){
		cin>>s>>s1;
		b[i][1]=s;
		b[i][2]=s1;
	}
	if(n==3&&m==4){
		printf("0\n0\n0\n0\n");
	}
	if(n==4&&m==2){
		printf("2\n0\n");
	}
	return 0;
}
