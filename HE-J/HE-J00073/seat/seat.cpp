#include<bits/stdc++.h>
using namespace std;
int n,m,a,num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2,b;i<=n*m;i++) cin>>b,num+=(b>a);
	for(int i=1;i<=m;i++){
		if(i%2==0)
			for(int j=n;j>=1;j--){
				num--;
				if(!num){cout<<i<<' '<<j;return 0;}
			}
		else for(int j=1;j<=n;j++){
			num--;
			if(!num){cout<<i<<' '<<j;return 0;}
		}
	}
	return 0;
}
