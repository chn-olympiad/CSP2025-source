#include<bits/stdc++.h>
using namespace std;

int n,m,a[200],x,cnt=1;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[cnt]==x){
				cout<<j<<" "<<i<<endl;
				return 0;	
			}
			cnt++;
		}
		j++;
		for(int i=n;i>=1;i--){
			if(a[cnt]==x){
				cout<<j<<" "<<i<<endl;
				return 0;	
			}
			cnt++;
		}
	}
	return 0;
}
