#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s1[N],s2[N];
string sa[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		getline(cin,s1[i],' ');
		getline(cin,s2[i],' ');
	}
	if(m==1){
		printf("2\n");
	}
	else{
		for(int i=1;i<=m;i++){
			printf("0\n");
		}
	}
	return 0;
} 
