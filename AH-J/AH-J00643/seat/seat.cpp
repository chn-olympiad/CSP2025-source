#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,t,k,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>t;a[1]=t,k=n*m;
	for(int i=2;i<=k;i++){cin>>a[i];}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		if(a[i]==t){
			cout<<x<<' '<<y;
			return 0;
		}
		if(x%2==1){y++;if(y>m){x++,y=m;}}
		else{y--;if(y==0){x++,y=1;}}
	}
}
