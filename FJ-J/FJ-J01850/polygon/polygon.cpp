#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],ans=0;;
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int m=0,g=0;
			for(int k=i;k<=j;k++){
				g+=a[k];
				m=max(a[k],m);
			}
			if(g>2*m){
				ans++;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
