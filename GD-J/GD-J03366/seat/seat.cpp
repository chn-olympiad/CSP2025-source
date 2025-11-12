#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000][10000],w[1000000],s,h,l;
int cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>w[i];
	}
	s=w[0];
	sort(w,w+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(i/m%2==0){
			a[i/m][i%n]=w[i];
		}
		else{
			a[i/m][n-1-i%n]=w[i];
		}
		if(w[i]==s){
			l=i/m;
			if(i/m%2==0){
				h=i%m;
			}
			else{
				h=n-1-i%n;
			}
		}
	}
	cout<<l+1<<" "<<h+1;
	return 0;
} 
