#include<bits/stdc++.h>
using namespace std;
const int N=1005;
struct node{
	int v,id;
}a[N];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int hang=0,lie=1,turn=1;
	for(int i=1;i<=n*m;i++){
		hang+=turn;
		if(hang==n+1)hang=n,lie++,turn=-turn;
		else if(hang==0)hang=1,lie++,turn=-turn;
		if(a[i].id==1){
			printf("%d %d",lie,hang);
			return 0;
		}
	}
	return 0;
}

