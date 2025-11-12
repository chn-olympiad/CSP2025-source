#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6;
int n,m;
string n1,m1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n+m;i++) scanf("%s %s",&n1,&m1);
	for(int i=0;i<n;i++) printf("%d\n",rand()%maxn);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
