#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[100000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    int x=0,y=0;
    for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(ans==a[i]){
			ans=i;
		}
	}
	x=ceil(1.0*ans/n);
	if(x%2==0){
		if(ans%n==0){
			y=1;
		}
		else if(ans%n==1){
			y=n;
		}
		else{
			y=n-(ans%n);
		}
	}
	else{
		y=ans%n;
		if(y==0){
			y=n;
		}
	}
	cout<<x<<" "<<y;
    return 0;
}
