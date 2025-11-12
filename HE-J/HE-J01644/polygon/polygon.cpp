#include <bits/stdc++.h>
using namespace std;

int n;
const int N=5010;
int a[N];

int sumx(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum+=a[i];
	}
	return sum;
}
int plusx(int l,int r,int k){
	int res=0;
	if(k-a[r]>a[l]){
		res+=plusx(l,r-1,k-a[r]);
	}
	else{
		for(int i=1;i<=r-l+1;i++){
			res+=i;
		}
	}
	for(int i=l;i<r;i++){
		for(int j=i;j<r;j++){
			if(k<sumx(i,j)) res++;
		}
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cout<<plusx(1,n-1,a[n]);
	return 0;
}

