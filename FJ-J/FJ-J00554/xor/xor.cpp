#include <bits/stdc++.h>
using namespace std;
int m=0;
struct Q{
	int left;
	int right;
	int val;
};
int ab(Q q[],int n){
	int max,x;
	if(n==m-1){
		return 1;
	}
	int o=n+1;
	while(q[n].right>=q[o].left){
		o++;
	}
	while(o!=m-1){
		x=ab(q,o);
		if(x>max){
			max=x;
		}
	}
	return max+1;
}
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k,z=0,v,max,d;
	cin>>n>>k;
	int a[n];
	Q q[(n+1)*n/2];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			v=a[i];
			for(int l=i;l<=j;i++){
				v=v^a[l];
			}
			if(v==k){
				q[z].left=i;
				q[z].right=j;
				q[z].val=v;
				m++;
			}
		}
	}
	for(int i=0;i<m;i++){
		d=ab(q,i);
		if(d>max){
			max=d;
		}
	}
	cout<<max;
	return 0;
}
