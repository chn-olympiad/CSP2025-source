#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	if(cnt/n%2==1){
		cout<<cnt/n+1<<" "<<m-cnt%n;	
	}
	else{
		cout<<cnt/n+1<<" "<<cnt%n+1;	
	}
	return 0;
}
