#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],c[110],k,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				++cnt;
				b[a[n*m-cnt+1]]=i;
				c[a[n*m-cnt+1]]=j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				++cnt;
				b[a[n*m-cnt+1]]=i;
				c[a[n*m-cnt+1]]=j;
			}
		}
	}
	cout<<b[k]<<" "<<c[k];
	return 0;
}
