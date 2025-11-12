#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N]; 
int aaa[N];
int g[N][35];
int u[N][35];
int aa[N][35];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bool vv=false;
	bool vis=false;
	int ab=1;
	int n;
	cin>>n;
	int k;
	int len=1;
	cin>>k;
	int ans=0;
	int jl=0;
	int l;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aaa[i]=a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=33;j>=0;j--){
			if(a[i]>=pow(2,j)){
				a[i]-=pow(2,j);
				g[i][j]=1;
				vis=true;
			}else{
				g[i][j]=0;
			}
		}
		vis=false;
	}
	for(int i=1;i<n;i++){
		for(int p=1;p<=n;p++){
			for(int j=33;j>=0;j--){
				if(p==1){
					aa[p][j]=g[i][j];
				}else{
					aa[p][j]=u[i-1][j-1];
				}
			}
			for(int j=33;j>=0;j--){
				
				if(aa[p][j]==g[p+1][j]){
					u[p][j]=0;
				}else{
					u[p][j]=1;
				}
			}
			for(int j=0;j<=33;j++){
				if(aa[p][j]==1){
					jl+=pow(2,j);
				}
			}
		
			if(jl==k){
				ans++;
				jl=0;
				len=i-len;
				l=i+1;
				break;
			}else{
				ab++;
			}
		}
		ab=1;
	}
	for(int i=1;i<=n;i++){
		if(aaa[i]==k){
			ans++;
			break;
		}
	}
	
	cout<<ans;
	return 0;
}