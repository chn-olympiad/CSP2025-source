#include<bits/stdc++.h> 
using namespace std;
int a[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			s=a[1][1];
			if(a[i][j]>s){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	int o=ans%n,p=ans/n;
	
	cout<<o<<" "<<p<<endl;
	if(p%2==0){
		if(o==0){
			o=1;
			p--;
			cout<<p+1<<" "<<o;
			return 0;
		}
		cout<<p+1<<" "<<o;
	}
	else{
		if(o==0){
			p--;
			cout<<p+1<<" "<<n-o;
			return 0;
		}
		cout<<p+1<<" "<<n+1-o;
	}
	return 0;
}
