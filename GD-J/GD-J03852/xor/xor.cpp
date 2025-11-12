#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int f[500005];
int cnt[257],tmp[257];
int  main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=0,flag2=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)flag=1;
		if(a[i]>255)flag2=1;
	}
	if(!flag){
		if(k>1){
			cout<<0;
			return 0;
		}
		int lst=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				if(k){
					f[i]=f[i-1]+1;
				}
				else{
					f[i]=max(f[i-1],f[lst-1]+1);
				}
				lst=i;
			}
			else{
				if(k){
					f[i]=max(f[i-1],f[lst-1]+1);
				}
				else{
					f[i]=f[i-1];
				}
			}
		}
		cout<<f[n];
		return 0;
	}
	else if(!flag2){
		for(int i=1;i<=n;++i){
			for(int j=0;j<=255;++j){
				if(cnt[j]>0){
					if(!tmp[j^a[i]])tmp[j^a[i]]=cnt[j];
					else tmp[j^a[i]]=min(tmp[j^a[i]],cnt[j]);
				}
			}
			for(int j=0;j<=255;++j){
				cnt[j]=tmp[j];
				tmp[j]=0;
			}
			cnt[a[i]]=i;
			if(cnt[k]){
				f[i]=max(f[i-1],f[cnt[k]-1]+1);
			}
			else f[i]=f[i-1];
		}
		cout<<f[n];
		return 0;
	}
	else{
		for(int i=1;i<=n;++i){
			int num=a[i];
			int j=i-1;
			while(num!=k&&j>=1){
				num^=a[j];
				--j;
			}
			if(num==k){
				f[i]=max(f[i-1],f[j]+1);
			}
			else f[i]=f[i-1];
		}cout<<f[n];
		return 0;
	}
	return 0;
}
