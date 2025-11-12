#include<bits/stdc++.h>
using namespace std;
int a[100],n,m,sum=1,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			sum++;
		}
	}
	b=sum/n;
	c=sum%n;
	if((b+1)%2==1){
		cout<<b+1<<c;
	}else{
		cout<<b+1<<n+1-c;
	}
	return 0;
}
