#include<bits/stdc++.h>
using namespace std;
int n,m,l,ans;
int a[40];
int main() {
 	freopen("poligon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	int t=n;
	for(int j=0;j<n;j++){
		for(int k=j+1;k<n;k++){
			for(int o=k+1;o<n;o++){
				l=a[j]+a[k]+a[o];
				m=max(a[j],max(a[k],a[o]));
				if(l>2*m) ans++;
			}
		}
	}
	cout<<ans;
} 
