#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,r;
struct node{
	bool r;
	int num;
}arr[1001];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	k=n*m;
	for(int i=1;i<=k;++i)scanf("%d",&arr[i].num);
	arr[1].r=true;
	stable_sort(arr+1,arr+1+k,cmp);
	for(int i=1;i<=k;++i){
		if(arr[i].r){
			k=i;
			break;
		}
	}
	c=k/n;
	if(k%n){
		if(c%2)r=n-k%n+1;
		else r=k%n;
		++c;
	}else{
		if(c%2)r=n;
		else r=1;
	}
	printf("%d %d",c,r);
	return 0;
}

