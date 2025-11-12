#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t , n , a[10000][10000];
int a1=0,a2=0,a3=0,x=0;
int ans=0;
int main (){
	cin >>t;
	while(t>0){
			cin >> n;
		for (int i=1 ; i <= n; i++ ){
			for (int j=1;j <= 3; j++){
				cin>>a[i][j];
			}
		}
		for (int i=1 ; i <= n; i++ ){
			for (int j=1;j <= 3; j++){
				x=max(a[i][1],a[i][2]);
				x=max(x,a[i][3]);
				if(x==a[i][1])	a1++;
				if(x==a[i][2])	a2++;
				if(x==a[i][3])	a3++;
				if((a1>n/2||a2>n/2||a3>n/2)&&x==a[i][1]){
					x=min(x,a[i][2]);
					x=max(x,a[i][3]);
				}
				if((a1>n/2||a2>n/2||a3>n/2)&&x==a[i][3]){
					x=min(x,a[i][2]);
					x=max(x,a[i][1]);
				}
				if((a1>n/2||a2>n/2||a3>n/2)&&x==a[i][2]){
					x=min(x,a[i][1]);
					x=max(x,a[i][3]);
				}

			}	ans+=x;
			x=0;a1=0;a2=0;a3=0;
		}
	cout<<ans<<endl;
	ans=0;
t--;}

return 0;
}
