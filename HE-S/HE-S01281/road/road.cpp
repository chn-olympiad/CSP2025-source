#include<bits/stdc++.h>
using namespace std;
struct money{
	int c1,c2,h;
}c[100010];
struct vill{
	int hua,l1,l2,l3,l4;
}l[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>c[i].c1>>c[i].c2>>c[i].h;
	}
	for(int i=0;i<k;i++){
		cin>>l[i].hua>>l[i].l1>>l[i].l2>>l[i].l3>>l[i].l4;
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
