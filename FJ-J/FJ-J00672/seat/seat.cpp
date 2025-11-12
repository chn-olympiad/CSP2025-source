#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;i++){//lie 
		if(a[i]==x){
			if(i/m%2==0){
				cout<<i/m+1<<" "<<i%m+1;
			}else{
				cout<<i/m+1<<" "<<n-i%m;
			}
			return 0;
		}
	}
	return 0;
} 
