#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	int s[n][m];
	for(int i=1;i<=nm;i++)cin>>a[i];
	int r=a[1];
	for(int i=1;i<=nm;i++){
		int maxn=0;
		for(int j=1;j<=nm;j++){
			if(a[j]>a[maxn])maxn=j;
		}
		b[i]=a[maxn];
		a[maxn]=0;
	}
	int ans;
	for(int i=1;i<=nm;i++){
		if(b[i]==r)ans=i;
	}
	if(ans>n){
		if(n%2==0){
			if(ans%n==0) cout<<ans/n<<" "<<m-(ans%n);
			else cout<<ans/n+1<<" "<<m;
		}
		else{
			if(ans%n==0) cout<<ans/n<<" "<<1;
			else cout<<ans/n+1<<" "<<ans%n;
		}
	}
	else cout<<1<<" "<<ans;
	return 0;
}
