#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans=0;
void sb(int x,int y,int z,int ma){
	if(x>n){
		if(y>=3&&z>ma){
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	else{
		sb(x+1,y,z,ma);
		ma=max(ma,2*a[x]);
		z+=a[x];
		y++;
		sb(x+1,y,z,ma);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sb(1,0,0,0);
	cout<<ans;
} 
