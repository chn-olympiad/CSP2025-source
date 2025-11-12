#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,si_1,si_2,ti_1,ti_2,x,y,z,x_1,y_1,z_1,ans=0;
	cin>>n>>q>>si_1>>si_2>>ti_1>>ti_2>>x>>y>>z>>x_1>>y_1>>z_1;
	if(x!=x_1){
		x=x_1;
		ans++;
	}
	if(y!=y_1){
		y=y_1;
		ans++;
	}
	if(z!=z_1){
		z=z_1;
		ans++;
	}
	for(int i=1;i<=q;i++){
		cout<<ans<<endl;
		ans=ans+1/2;
	}
	return 0;
}
