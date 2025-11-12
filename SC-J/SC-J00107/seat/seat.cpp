#include<bits/stdc++.h>
using namespace std;
const int MAXN=101;
int n,m;
int a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],id;
	sort(a+1,a+n*m+1,cmp); 
	for(int i=1;i<=n*m;i++)
		if(a[i]==r){
			id=i;
			break;
		}
	int ans1=id/n,ans2=id%n;
	if(ans1%2==0){
		if(ans2==0) cout<<ans1<<' '<<1;
		else cout<<ans1+1<<' '<<ans2;
	}
	else{
		if(ans2==0) cout<<ans1<<' '<<n;
		else cout<<ans1+1<<' '<<n-ans2+1;
	}
	return 0;
}