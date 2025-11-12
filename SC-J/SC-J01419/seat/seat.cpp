#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000],b[10000][10000];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ll n,m,man,l=1;
	freopen("seat.in","r",n);
	freopen("seat.in","r",m);
	for(int i=1;i<=n*m;i++){
		freopen("seat.in","r",a[i]);
		if(i==1){
			man=a[i];
		}
	} 
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[l];
				l++;
				if(b[i][j]==man){
					freopen("seat.out","w",i );
					freopen("seat.out","w",j);
					return 0;
				} 
			}
		}else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[l];
				l++;
				if(b[i][j]==man){
					freopen("seat.out","w",i );
					freopen("seat.out","w",j);
					return 0;
				} 
			}
		} 
	} 
	return 0;
} 