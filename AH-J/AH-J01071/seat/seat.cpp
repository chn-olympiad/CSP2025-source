#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int jz=0;
	int ans=1;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>jz;
		}else{
			int l;
			cin>>l;
			if(l>jz){
				ans++;
			}		
		}
	}
	//ans=7
	int y=0;
	if(ans%n==0){
		y=ans/n;
		cout<<y<<' ';
		if(y%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
		
	}else{
		y=ans/n+1;
		cout<<y<<' ';
		if(y%2==0){
			cout<<n-ans%n;
			
		}else{
			cout<<ans%n;
		}
				
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
