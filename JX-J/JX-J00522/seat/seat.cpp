#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m);
	int k=lower_bound(a+1,a+1+n*m,t)-a;
	k=n*m-k;
	int x=1,y=1;
	while(k--){
		if(y%2){
			if(x<n) x++;
			else y++;
		}else{
			if(x>1) x--;
			else y++;
		}	
	}cout<<y<<' '<<x<<'\n';
	return 0;
}
