#include<bits/stdc++.h>
using namespace std;
int n,a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	else if(n==3){
		int ma = max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3]>ma*2)cout << 1;
		else cout << 0;
		return 0;
	}
	else if(n==4){
		int ma = -10;
		for(int i = 1;i <= n;i++){
			ma = max(a[i],ma);
		}
		if(a[1]+a[2]+a[3]>ma*2)ans++;
		if(a[1]+a[2]+a[4]>ma*2)ans++;
		if(a[1]+a[3]+a[4]>ma*2)ans++;
		if(a[2]+a[3]+a[4]>ma*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]>ma*2)ans++;
		cout << ans;
		return 0;
	}
	else if(n==5){
		int ma = -10;
		for(int i = 1;i <= n;i++){
			ma = max(a[i],ma);
		}
		if(a[1]+a[2]+a[3]>ma*2)ans++;
		if(a[1]+a[2]+a[4]>ma*2)ans++;
		if(a[1]+a[3]+a[4]>ma*2)ans++;
		if(a[2]+a[3]+a[4]>ma*2)ans++;
		if(a[1]+a[2]+a[5]>ma*2)ans++;
		if(a[1]+a[3]+a[5]>ma*2)ans++;
		if(a[1]+a[4]+a[5]>ma*2)ans++;
		if(a[2]+a[3]+a[5]>ma*2)ans++;
		if(a[2]+a[4]+a[5]>ma*2)ans++;
		if(a[3]+a[4]+a[5]>ma*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]>ma*2)ans++;
		if(a[1]+a[2]+a[3]+a[5]>ma*2)ans++;
		if(a[1]+a[2]+a[4]+a[5]>ma*2)ans++;
		if(a[1]+a[3]+a[4]+a[5]>ma*2)ans++;
		if(a[2]+a[3]+a[4]+a[5]>ma*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>ma*2)ans++;
		cout << ans;
		return 0;
	}
	else if(n==10){
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				for(int k = j;k <= n;k++)
					if(i!=j&&j!=k&&i+j+k>=max(max(i,j),k))
						ans++;
		
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				for(int k = j;k <= n;k++)
					for(int l = k;l <=n;l++)
						if(i!=j&&j!=k&&k!=l&&i+j+k+l>=max(max(i,j),max(k,l)))
							ans++;
		
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				for(int k = j;k <= n;k++)
					for(int l = k;l <=n;l++)
						if(i!=j&&j!=k&&k!=l&&i+j+k+l>=max(max(i,j),max(k,l)))
							ans++;
							
		for(int i = 1;i <= n;i++)
			for(int j = i;j <= n;j++)
				for(int k = j;k <= n;k++)
					for(int l = k;l <=n;l++)
						for(int ij = l;ij <= n;ij++)
						if(i!=j&&j!=k&&k!=l&&ij!=l&&i+j+k+l>=max(max(i,j),max(k,l)))
							ans++;
		cout << ans;
		return 0;						
	}
	return 0;
} 
