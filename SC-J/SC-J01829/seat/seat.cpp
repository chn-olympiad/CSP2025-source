#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n*m+10],k=0;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			k++;
		}
	}
	if((k/m+1)%2==1){
		cout<<k/m+1<<" "<<(k%m)+1;
	}else{
		cout<<k/m+1<<" "<<m-k%m;
	}
	return 0;
}
