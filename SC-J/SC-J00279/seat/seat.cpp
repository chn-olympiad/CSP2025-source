#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int m,n,a[101],sum,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
			sum++;
		}
	}m1=1;
	sum++;
	for(;sum>0;sum--){
		if(m1%2==0){
			n1--;
			if(n1==0){
				m1++;
				n1=1;
			}
		}else{
			n1++;
			if(n1==n+1){
				m1++;
				n1=n;
			}
		}
	}cout<<m1<<" "<<n1;
	return 0;
}