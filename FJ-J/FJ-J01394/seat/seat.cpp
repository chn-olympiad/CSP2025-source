#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,sum,cnt;    
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int temp=a[1];
	sort(a+1,a+(m*n)+1);
	for(int i=m*n;i>=1;i--){
		if(temp==a[i]){
			cnt=(n*m)-i+1;
			break;
		}
    }
	sum=((cnt-1)/n)+1;
	cnt=cnt%n;
    if(sum%2==0){
    	if(cnt==0)cout<<sum<<" "<<1;
		else cout<<sum<<" "<<n-cnt+1;
	}
	else {
		if(cnt==0)cout<<sum<<" "<<n;
		else cout<<sum<<" "<<cnt;
	}
	return 0;
}
