#include<bits/stdc++.h>
using namespace std;
int n,m,r,b[105],sum=1;
int pd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	r=b[1];
	sort(b+1,b+1+n*m,pd);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[sum]==r){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			sum++;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(b[sum]==r){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			sum++;
		}
	}
    return 0;
}
