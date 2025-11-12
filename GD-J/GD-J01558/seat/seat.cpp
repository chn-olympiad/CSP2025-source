#include<bits/stdc++.h>
using namespace std;
int n,m,marks[105],num,x,y;
bool cmp(int x,int y){
	return x>y;
}
int find_in_marks(int x){
	int left=0,right=n*m+1;
	while(left<=right){
		int mid=(left+right)/2;
		if(marks[mid]==x)return mid;
		if(marks[mid]>x)left=mid+1;
		if(marks[mid]<x)right=mid-1;
	}
	return -1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(marks,0,sizeof(marks));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&marks[i]);
	}
	num=marks[1];
	sort(marks+1,marks+n*m+1,cmp);
	num=find_in_marks(num);
	x=num%n==0?num/n:num/n+1;
	y=x%2==0?m-num+(x-1)*n+1:num-(x-1)*n;
	printf("%d %d",x,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
