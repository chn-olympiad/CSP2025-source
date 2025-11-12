#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],len,x,idx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i]==x){
			idx=i;
			break;
		}
	}
	int first=ceil((double)idx/n);
	int second=0;
	if(first%2==1){
		second=idx%m;
		if(second==0){
			second=m;
		}
	}else{
		second=m-idx%m+1;
		if(second==0){
			second=1;
		}
	}
	printf("%d %d",first,second);
	return 0;
}
