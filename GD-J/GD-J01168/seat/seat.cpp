#include <bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y){
	return x>y;
} 
int a[110];
int find(int k){
	int l=0,r=n*m-1,mid;
	while(l<r){
		mid=l+(r-l)/2;
		if(a[mid]==k){
			return mid;
		}
		else if(a[mid]>k){
			l=mid+1;
		}
		else r=mid-1;
	} 
	return l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[0];
	//排序 
	sort(a,a+n*m,cmp);
	
	//查找
	//这个范围应该暴力也能过，保险起见用二分查找
	int pm=find(xiaor);
	//计算 
	int c=pm/n,r;
	if(c%2==0){//正序 
		r=pm%n;
	}
	else r=n-pm%n-1;
	cout<<c+1<<" "<<r+1;
	return 0;
} 
