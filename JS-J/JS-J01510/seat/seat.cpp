#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ms,a[105];
	scanf("%d%d%d",&n,&m,&a[0]);
	ms=a[0];
	for(int i=1;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n*m,cmp);
	int k;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==ms){
			k=i+1;
			break;
		}
	}
	int ans=ceil(k*1.0/n);
	cout<<ans<<" ";
	int anss=k%n;
	if(anss==0) anss=n;
	if(ans%2==0) cout<<n+1-anss;
	else cout<<anss;
	return 0;
}
