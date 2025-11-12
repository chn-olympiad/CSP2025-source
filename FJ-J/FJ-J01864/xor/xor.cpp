#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],p[100010],num,kx,ans,i;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]++;
	}
	for(int i=0;i<=255;i++){
		if(p[i]>0) num++;
	}
	if(num==1&&p[1]>0){
		if(k==0){
			cout<<n/2;
			return 0;
		}else
		if(k==1){
			cout<<0;
			return 0;
		}
		return 0;
	}else if(num==1&&p[0]>0){
		if(k==0){
			cout<<n;
			return 0;
		}else
		if(k==1){
			cout<<0;
			return 0;
		}
	}else if(num==2&&p[0]>0&&p[1]>0){
		cout<<p[k];
		return 0;
	}else if(num>2){
		while(i<n){
			i++;
			if(a[i]==k){
				ans++;
				kx=0;
				continue;
			}else if(a[i]!=k){
				kx=kx^a[i];	
				if(kx==k){
					ans++;
					kx=0;
					continue;
				}else continue;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

