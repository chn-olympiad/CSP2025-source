#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+4;
int T;
int a[N],b[N],c[N],ans=-1,n;

void dfs(int x,int y,int z,int step,int num){
	//cout<<x<<" "<<y<<" "<<z<<"\n"<<step<<" "<<num<<" "<<a[num]<<"\n"; 
	if(x+y+z==n){
		ans=max(ans,step);
		return;
	}
	if(x<n/2) dfs(x+1,y,z,step+a[num],num+1);
	if(y<n/2) dfs(x,y+1,z,step+b[num],num+1);
	if(z<n/2) dfs(x,y,z+1,step+c[num],num+1);
	return;
} 

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=-1;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
