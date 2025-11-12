#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],xs[500005],f[10005][10005];
bool sp_1(){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag=0;
			break;
		}
	}
	return flag&&k==0;
}
bool sp_2(){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			flag=0;
			break;
		}
	}
	return flag&&k<=1;
}
bool sp_3(){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]>255){
			flag=0;
			break;
		}
	}
	return flag&&k<=255;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xs[i]=xs[i-1]^a[i];
	}
	if(sp_1()){
		cout<<n/2;
		return 0;
	}else if(sp_2()){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				else if(a[i]==1){
					if(a[i+1]==1){
						cnt++;
						i++;
					}
				}
			}
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
				else if(a[i]==0){
					if(a[i+1]==1){
						cnt++;
						i++;
					}
				}
			}
		}
		cout<<cnt;
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==k)cnt++;
		cout<<cnt;
	}
	return 0;
}
