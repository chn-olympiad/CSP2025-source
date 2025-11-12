#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N],jh[25][N],kh[25],sum[25][N],cnt=0,mx,ans=0;
int yh(int x,int y){
	int ans=0,xnode,ynode;
	for(int i=21;i>=0;i--){
		if(x>=(1<<i))xnode=1,x-=(1<<i);
		else 		 xnode=0;
		if(y>=(1<<i))ynode=1,y-=(1<<i);
		else 		 ynode=0;
		if((xnode+ynode)%2==1) ans+=(1<<i);
		cout<<xnode<<' '<<ynode<<' '<<ans<<endl;
	}
	return ans;
}
void change_k(int x){
	for(int i=21;i>=0;i--){
		if(x>=(1<<i)) 
			kh[i]=1,x-=(1<<i);
	}
}
void change(int x,int ides){
	for(int i=21;i>=0;i--){
		if(x>=(1<<i)) 
			jh[i][ides]=1,x-=(1<<i);
	}
}
void add(int ides){
	for(int i=0;i<=21;i++)
		sum[i][ides]=(sum[i][ides-1]+jh[i][ides])%2;
}
int cheak(int x,int y){
//	cout<<"x,y:"<<x<<' '<<y<<endl;
	for(int i=0;i<=21;i++){
//		cout<<i<<' '<<sum[i][x]-sum[i][y]+2%2<<' '<<kh[i]<<endl;
		if((sum[i][x]-sum[i][y]+2)%2!=kh[i]){
//			cout<<"NO\n";
			return -1;
		}
	}
//	cout<<"YES\n";
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	change_k(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		change(a[i],i);
		add(i);
	}
	while(cnt<=n){
//		cout<<"cnt:"<<cnt<<endl;
		int j=cnt+1;
		for(;j<=n;j++){
			if(cheak(j,cnt)==1)
				break;
		}
//		cout<<"cnt:"<<cnt<<",j:"<<j<<endl;
		if(j<=n)ans++;
//		cout<<"ans:"<<ans<<endl;
		cnt=j;
	}
	cout<<ans;
	return 0;
}