#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	int js;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			js=n*m-i+1;
			break;
		}
	}
	t=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				t++;
				if(t==js) cout<<j<<" "<<i;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				t++;
				if(t==js) cout<<j<<" "<<i;
				}
		}
	}
	return 0;
}
