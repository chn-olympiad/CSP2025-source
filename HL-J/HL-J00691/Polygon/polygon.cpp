#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int t=0,aa=i;
		for(int j=i-1;j>=0;j--){
			int ab=j;
			if(a[aa]>a[ab]){
				t=a[aa];
				a[aa]=a[ab];
				a[ab]=t;
				aa--;
			}
		}
	}
	int m=3;
	int b=1,c=2;
	for(int i=0;i<n;i++){
		if(m==3){
			
			if(a[i]+a[i+b]+a[i+c]>2*a[i+2]){
				ans++;
			}
			if(b>c){
				c++;
			} else{
				b++;
			}
			if(i+b>=n||i+c>=n){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
