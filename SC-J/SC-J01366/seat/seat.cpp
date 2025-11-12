#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[10000005],r,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(r==a[i]){
			r=n*m-i+1;
		}
	}for(int i=1,R=0;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				R++;
				if(R==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				R++;
				if(R==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
//ccf我爱你，就像老鼠爱大米