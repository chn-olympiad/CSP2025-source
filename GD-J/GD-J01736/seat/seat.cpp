#include<bits/stdc++.h>
using namespace std;
#define ll long long
	int n,m,t,a[200],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){//ап 
		if(t>=a[n*i]){
			c=i;
			if(i%2){
				for(int j=1;j<=n;j++){
					if(t==a[n*i-n+j]){
						r=j;break;
					}
				}
			}
			else{
				for(int j=n;j>=1;j--){
					if(t==a[n*i-j+1]){
						r=j;break;
					}
				}
			}
			break;
		}
	}cout<<c<<" "<<r;
	
	return 0; 
}
