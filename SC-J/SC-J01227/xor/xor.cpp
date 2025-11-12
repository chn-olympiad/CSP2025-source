#include<bits/stdc++.h>
using namespace std;
int a[500050];
int sum[1005][1005];
int tot[500050];
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int f1=1;//f1全一
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f1=0;
	}
	if(f1){
		int s=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k) s++;
		}
		cout<<s<<'\n';
		return 0;
	}
	else{
		long long res=0;
		for(int i=1;i<=n;i++){
			sum[i][i]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum[i][j]=sum[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int p=i;p<=n;p++){
				for(int j=p;j<=n;j++){
					if(sum[p][j]==k){
						res++;
						p=j+1;
					}
				}
			}
			ans=max(ans,res);
			res=0;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}//30+