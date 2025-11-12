#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[145],b[145];
int c,r;
int f(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,f);
	int l=1,r=n*m;
	while(l<r){
		int mid=l+(r-l)/2;
		if(b[mid]==a[1]){
			int q,p=(mid-1)/n+1;
			q=mid%n;
			if(q==0){
				q=n;
			}
			if(p%2!=1){
				q=n-q+1;
			}
			cout<<p<<" "<<q;
			break;
		}else if(b[mid]>=a[1]){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return 0;
} 
