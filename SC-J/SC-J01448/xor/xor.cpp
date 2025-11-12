#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1005000];
int shifou=0;
int qujian[1050][1050];
int visjilu[1005000];
bool jiancha(int l,int r){
	for(int i=l;i<=r;i++){
		if(visjilu[i]!=0)return 0;
	}
	return 1;
}
int daan;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)shifou=1;
		if(a[i]>1)shifou=2;
	}
	if(k==0&&shifou==0){
		cout<<n/2;
	}else if(k<=1&&shifou!=2){
		int ling=0,yi=0;
		if(k==0){
			
			for(int i=1;i<=n;i++){
				if(a[i]==0)ling++;
				else yi++;
			}
			cout<<ling+yi/2;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ling++;
				else yi++;
			}
			cout<<yi;
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int ans=a[i];
				for(int k=i+1;k<=j;k++){
					ans^=a[k];
				}
				qujian[i][j]=ans;
			}
		}
		for(int len=1;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				if(qujian[l][r]==k&&jiancha(l,r)){
					for(int i=l;i<=r;i++){
						visjilu[i]=1;
					}
					daan++;
				}
			}
		}
		cout<<daan;
	}
	return 0;
}