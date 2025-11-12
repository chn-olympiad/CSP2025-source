#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b,c,js;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<n;i++){
		for(int j=1;j<=n;j++){
			for(int r=j;r<=j+i;r++){
				b+=a[r];
				c=a[r+j];
			}
			if(b>c*2){
				js++;
			}
		}
	}
	cout<<js;
	return 0;
}
