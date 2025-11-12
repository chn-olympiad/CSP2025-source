#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c[105];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n>>m;
    int s=1;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]){
		cout<<1;
	}
    return 0;
}
