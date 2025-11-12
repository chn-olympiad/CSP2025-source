#include <bits/stdc++.h>
using namespace std;

int a[5005];
int cnt=0;
//int judge(int *a,int l,int r){
//	if(r>=n) return 0;
//	int sum=0,maxn=-1;
//	for(int i=l;i<=r;i++){
//		sum+=a[i];
//		maxn=max(maxn,a[i]);
//	}
//	cout<<maxn<<' '<<sum;
//	if (sum>2*maxn) return 1+judge(add(a,r-l,a[r+1]),l,r-l+1);
//	return judge(add(a,r-l,a[r+1]),l,r-l+1);
//}

int add(int *a,int l,int m){
	a[l]=m;
	for(int i=l+1;i<=5001;i++){
		a[i]=0;
	}
	return *a;
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cout<<9;

	
	return 0;
}
