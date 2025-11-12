#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ka;
int pow_2[25];
bool k[25];
bool a[500005][25];
bool sum[500005][25];
bool nf[25];
int can[500005],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pow_2[0]=1;
	for(int i=1;i<=22;i++){
		pow_2[i]=pow_2[i-1]*2;
	}
	cin>>n>>ka;
	for(int i=20;i>=1;i--){
		if(ka>=pow_2[i]){
			k[i]=1;
			ka-=pow_2[i];
		}
	}
	for(int i=1;i<=n;i++){
		int sa;
		cin>>sa;
		for(int j=20;j>=1;j--){
			if(sa>=pow_2[j]){
				a[i][j]=1;
				sa-=pow_2[j];
			}
		}
	}
	for(int i=1;i<=20;i++){
		sum[1][i]=a[1][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			if(sum[i][j]==a[i][j]){
				sum[i][j]=0;
			}else{
				sum[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){//may can be logn
			for(int i=1;i<=20;i++){
				if(sum[l-1][i]==sum[r][i]){
					nf[i]=0;
				}else{
					nf[i]=1;
				}
			}
			bool flag=1;
			for(int i=1;i<=20;i++){
				if(nf[i]!=k[i]){
					flag=0;
					break;
				}
			}
			if(l==r){
				bool fg=1;
				for(int i=1;i<=20;i++){
					if(a[l][i]!=k[i]){
						fg=0;
						break;
					}
				}
				if(fg==1){
					can[l]=l;
					break;
				}
			}
			if(flag==1){
				can[l]=r;
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<can[i]<<" ";
//	}cout<<"\n";
	for(int s=1;s<=n;s++){
		int noww=s,cnt=0;
		bool iss=0;
//		cout<<s<<"jjj\n";
		while(1){
//			cout<<noww<<"\n";
			if(noww>=n){
				break;
			}
			if(can[noww]==0){
				iss=0;
				noww++;
			}
			else if(can[noww]==noww){
				if(iss==1){
					cnt--;
				}
				iss=1;
				noww++;
				cnt++;
			}
			else{
				iss=0;
				noww=can[noww];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}