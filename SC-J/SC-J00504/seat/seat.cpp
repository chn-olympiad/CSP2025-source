#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int x,idx;
};
Node a[10000];
bool cmp(Node a,Node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i <= n*m;i++){
		scanf("%d",&a[i].x);
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int u=0;
	for(int i=1;i <= n*m;i++){
		if(a[i].idx==1){
			u=i;
		}
	}
	int i=1,j=1,p=1;
	while(1){
		if(p==u){
			cout<<i<<' '<<j;
			return 0;
		}
		if(i&1){
			j++;
			if(j>n){
				i++;
				j=n;
			}
		}else{
			j--;
			if(j==0){
				i++;
				j=1;
			}
		}
		p++;
	}
	return 0;
}