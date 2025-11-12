#include<bits/stdc++.h>
using namespace std;
#define MAXN 110
int n,m;
struct node{
	int s,id;
}a[MAXN];
bool cmp(node pre,node nxt){
	return pre.s>nxt.s||(pre.s==nxt.s&&pre.id<nxt.id);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
//			cout<<i<<"\n";
			int k=(i%m==0?i/m:i/m+1);
			cout<<k<<" "<<(k%2?(i%m==0?m:i%m):m-i%m+1);
			return 0;
		} 
	}
	return 0;
}

