#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],q[500005],t[500005],l,r,cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	cnt++;
	q[cnt]=n+1;
	for(int i=n;i>=1;i--){
		if(a[i]==m){
			ans++;
			cnt++;
			q[cnt]=i;
		}
	}
	cnt++;
	q[cnt]=0;
	while(cnt>1){
		l=q[cnt];
		cnt--;
		r=q[cnt];
		for(int i=1;i<=r-l-1;i++){
			for(int j=l+1;j<=r-i;j++){
				if(((f[j-1]^f[j+i-1])==m&&t[j]==0)||((f[j-1]^f[j+i-1])==m&&i<=t[j])){
					ans++;
					for(int k=j;k<=j+i-1;k++){
						t[k]=i;
					}
					for(int k=l+1;k<j;k++){
						t[k]=i+j-k;
					}
					for(int k=j+i;k<=r-i;k++){
						t[k]=k-j+1;
					}
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
} 