#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k[15][15],l,s,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+l+1);
	for(int i=1,j=l;i<j;i++,j--){
		swap(a[i],a[j]);
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k[j][i]=a[++s];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k[j][i]=a[++s];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k[j][i]==f){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
