#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b,c,d,e;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
		c=a[0];
	}
    for(int i=0;i<=n*m-1;i++){
		for(int j=i;j<=n*m-1;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==c) b=i;
    }
    b++;
    d=b/n;
    if(b%n==0) cout<<d<<" ";
    else cout<<d+1<<" ";
    if(b%n==0&&d%2==1) cout<<n;
    else if(b%n==0&&d%2==0) cout<<1;
    else cout<<b-n*d; 
    return 0;
}
