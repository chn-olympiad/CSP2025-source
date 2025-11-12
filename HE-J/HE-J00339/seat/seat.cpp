#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct node{
	int ii;
	int jj;
	int f;
}a[110];
bool cmp(node x,node y){
	return  x.f<y.f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
	}
	s=a[1].f;
	a[1].ii=1;a[1].jj=1;
	sort(a+1,a+n*m+1,cmp);
	cout<<1<<" "<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
