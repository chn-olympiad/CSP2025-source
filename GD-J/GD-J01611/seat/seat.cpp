#include<bits/stdc++.h>
using namespace std;
int a[111],n,m,sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	int sumx=sum/n;
	if(sum%n==0){
		if(sumx%2==1) cout<<sumx<<" "<<n;
		else cout<<sumx<<" "<<"1";
		return 0;
	}
	if(sumx%2==0){
		cout<<sumx+1<<" "<<sum%n;
		return 0;
	}
    cout<<sumx+1<<" "<<n;
	return 0;
}
