#include<bits/stdc++.h>

using namespace std;

const int N=10001;

typedef long long ll;

int n,k;
int a[N];
bool b[500001];
ll s[N][N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
		s[i][i]=a[i];
		
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++)
			s[i][j]=s[i][j-1]^a[j];
	}
	
	ll ans=0;
	
	for(int i=1;i<=500001;i++)
		b[i]=true;
		
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[i][j]==k){
				if(b[i]==true&&b[j]==true){
					ans++;
					for(int k=i;k<=j;k++)
						b[k]=false;
				}
			}
		}
	}
	
	printf("%lld",ans);
}
