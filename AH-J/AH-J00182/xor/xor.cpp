#include<bits/stdc++.h>
using namespace std;
int n,T,l=0,ans=0;
int a[500005][25];
int sum[500005][25];
int t[25];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		int x,t=0;
		scanf("%d",&x);
		while(x){
			t++;
			a[i][t]=x%2;
			x/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=25;j++){
			sum[i][j]=(sum[i-1][j]+a[i][j])%2;
		}
	}
	int ti=0;
	while(T){
		t[++ti]=T%2;
		T/=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			int e=0;
			for(int k=1;k<=25;k++){
				int r=(sum[i][k]+sum[j][k])%2;
				if(r!=t[k]){
					e=1;
					break;
				}
			}
			if(e==0){
				ans++;
				l=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
