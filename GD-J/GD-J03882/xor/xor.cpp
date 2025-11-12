#include<bits/stdc++.h> 
using namespace std;
const int MAXN=500005;
int n,k;
int a[MAXN];
int f[2][MAXN];
int sum[MAXN];
bool p[MAXN];
int num;
int read(){
	int t;
	scanf("%d",&t);
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==k){
			num++;
		}
		sum[i]=a[i]^sum[i-1];
	}
	if(k==0){
		cout<<num;
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				continue;
			}
			for(int j=i+1;j<=n;j++){
				if((sum[j]^sum[i])==k && a[j]!=0){
					num++;
				}
			}
		}
		cout<<num;
		return 0;
	}
	int pi=1;
	for(int i=1;i<=n;i++){
		int s=i;
		while(s>=pi && sum[s]^sum[i]!=k){
			s--;
		}
		if(s!=pi){
			f[0][i]=max(f[1][s]+1,f[1][i]);
			pi=i;
		}
		f[1][i]=max(f[1][i-1],f[0][i-1]);
		if(a[i]==k && pi!=i){
			p[i]==true;
			pi=i;
			f[1][i]++;
		}
	}
	cout<<max(f[0][n],f[1][n]);
	return 0;
}
