//GZ-S00285 贵阳市第一中学 樊墨涵 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	string s1,s2;
}a[N];
int n,m;
string s,e,cen;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=m;i++){
		cin >>s>>e;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
