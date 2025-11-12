#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,k,i,j,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+n*m);
    i=1,j=1;
    while(a[n*m-cnt]!=k){
		if(j%2==1){
			i++;
		}else{
			i--;
		}
		if(i==n+1){
			j++;
			i=n;
		}
		if(i==0){
			j++;
			i=1;
		}
		cnt++;
	}
	cout<<j<<' '<<i;
	return 0;
}
