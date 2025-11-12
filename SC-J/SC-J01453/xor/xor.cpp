#include<bits/stdc++.h>
using namespace std;

const int N=1e+3;
int a[N+10];
int f[N+10][N+10];

struct lr{
	int l,r,v;
};
const int M=1e+7;
lr s[M+10];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
		f[i][i]=a[i];
	}
	
	for(int i=1; i<=n-1; i++){
		for(int j=i+1; j<=n; j++){
			f[i][j]=f[i][j-1]^f[j][j];
		}
	}
	
	int tot=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(f[i][j]==k){
				tot++;
				s[tot].l=i;
				s[tot].r=j;
				s[tot].v=1;
			}
		}
	}
	
	
	for(int i=2; i<=tot; i++){
		for(int j=1; j<=i; j++){
			if(s[j].r<s[i].l) s[i].v=max(s[i].v,s[j].v+1);
		}
	}
	int ans=1;
	for(int i=1; i<=tot; i++){
		ans=max(ans,s[i].v);
	}
	cout<<ans;

	return 0;
}
