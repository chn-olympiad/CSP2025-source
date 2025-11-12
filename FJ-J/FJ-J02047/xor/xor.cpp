#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,K,a[500005],f[500005][10],t[15],pf=2;
int search(int r){
	bool flg=0;
	for(int j=r+1;j<=n;j++){
		for(int i=j;i>=r+1;i--){
			memset(t,0,sizeof(t));
			for(int k=i;k<=j;k++){
				for(int l=1;l<=pf;l++){
					if(f[k][l]!=t[l]){
						t[l]=1;
					}
					else{
						t[l]=0;
					}
				}
			}
			flg=0;
			for(int l=1;l<=8;l++){
				if(t[l]!=f[0][l]){
					flg=1;
				}
			}
			if(!flg){
				//cout<<i<<' '<<j<<endl;
				return j;
			}
		}
	}//what the hell is this
	
	return -1;
}
signed main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;int tmp;
	f[0][0]=K;
	tmp=1;
	while(K){
		f[0][tmp++]=K%2;
		K/=2;
	}
	K=f[0][0];
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]>1) pf=8;
		tmp=1;
		while(a[i]){
			f[i][tmp++]=a[i]%2;
			a[i]/=2;
		}
	}
	int r=0,ans=0;
	while(r!=-1){
		r=search(r);ans++;
	}
	cout<<ans-1;
	cout<<endl;
	return 0;
}
/*
T3 finished.
i think this wierd code could give me 50 pts,60 if lucky
400+rand()%100
results in 424 idk whats the meaning but ok

rp++
idk why i thought of a function with 4 "for"s within each other but ok

*/
