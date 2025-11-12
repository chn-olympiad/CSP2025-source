#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
int c[500005];
long long ans;
int f(int cnt){
	int happy=0;
	for(int i=1;i<=n-cnt+1;i++){
		for(int j=i;j<=i+cnt-1;j++){
			b[j]=(b[j-1] xor a[j]);
			b[j-1]=0;
		}
		if (b[i+cnt-1]==k){
			int F=0;
			for(int j=i;j<=i+cnt-1;j++){
				if(c[j]){
					F=1;
					happy-=1;
					break;
				}
			}
			if(!F)for(int j=i;j<=i+cnt-1;j++) c[j]=1;
			happy++;
		}
		b[i+cnt-1]=0;
	}
	return happy;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans+=f(i);
	}
	cout<<ans;
	return 0;
}