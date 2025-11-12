#include<bits/stdc++.h>
using namespace std;
int n,t=0,a[10010],q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			for(int q=k+1;q<=n;q++){
				if((a[j]+a[k]+a[q])>(max(max(a[j],a[k]),a[q])*2)){
					t++;
				}
			}
		}
	}
	q=t;
	for(int i=4;i<n;i++){
		q*=2;
		t+=q;
	}
	cout<<t;
	return 0;
}
