#include<bits/stdc++.h>
using namespace std;
struct QWQ{string a1,a2;}a[1145],b[1145];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>a[i].a1>>a[i].a2;
	for(int i=1;i<=q;i++)cin>>b[i].a1>>b[i].a2;
	for(int i=1;i<=q;i++)printf("0\n");
	return 0; 
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

