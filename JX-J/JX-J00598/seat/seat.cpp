#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[101];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    int u=a[1];
    sort(a+1,a+sum+1);
    for(int i=1;i<=sum;i++){
        if(a[i]==u){
            u=sum-i+1;
            break;
        }
    }
    int k=u%m;
    if(k==0){
		int a=u/m;
		cout<<a<<" ";
		if(a%2==0) cout<<1;
		else cout<<m;
	}
	else{
		int a=(u-k)/m+1;
		cout<<a<<" ";
		if(a%2==0){
			cout<<m-k+1;
		}
		else cout<<k;
	}
}
