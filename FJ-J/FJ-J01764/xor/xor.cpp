#include<bits/stdc++.h>
using namespace std;
bool v,vis[500005];
int a[500005],n,k,js=1,znt=0,l;
int z10_2(int x){
	int y=x,cnt=0,z=1;
	while(y!=0){
		cnt+=y%2*z;
		z*=10;
		y/=2;
	}
	return cnt;
}
int yh(int x,int y){
	int z=1,cnt=0;
	while(x!=0||y!=0){
		if(x%10!=y%10){
			cnt+=z;
		}
		z*=10;
		x/=10;
		y/=10;
	}
	return cnt;
	 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k=z10_2(k);
	for(int i=1;i<=n;i++){
		cin>>l;
		a[i]=z10_2(l);
	}
	l=-1;
	while(js<=n){
		if(a[js]==k&&vis[js]==0){
			znt++;;
			js++;
			v=0;
			l=-1;
		}else if(l==k){
			znt++;
			vis[js+1]=0;
			js++;
			vis[js]=0; 
			v=0;
			l=-1;
			
		}else{
			if(v){
				l=yh(l,a[js+1]);
				vis[js+1]=1;
			}else if(js+1<=n){
				l=yh(a[js],a[js+1]);
				vis[js]=1;
				vis[js+1]=1;
				v=1;
			}
			js++;
		}
	}
	cout<<znt;
	return 0;
} 
