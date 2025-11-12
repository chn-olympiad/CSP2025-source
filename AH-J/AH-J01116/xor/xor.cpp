#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int s[500005][25];
int c[25];
int l[500005];
int maxn,sum;
int check(int r,int l){
	for(int i=1;i<=20;i++){
		if((s[r][i]-s[l-1][i]+2)%2!=c[i]){
			return 0;
		}
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int op=1<<19;
	for(int j=20;j>=1;j--,op>>=1){
	    if(k>=op){
			k-=op;
			c[j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		int u;
	    cin>>u;
	    op=1<<19;
	    for(int j=20;u>0||j>=1;j--){
			if(u>=op){
				u-=op;
				s[i][j]=1;
			}
			s[i][j]=(s[i][j]+s[i-1][j])%2;
			op/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){ 
			if(l[j]){
				break;
			}
			if(check(i,j)==1){
				l[i]=j;
				break;
			}
		}
	}	
	for(int i=1;i<=n;i++){
		if(l[i]){
			if(l[i]>maxn){
				sum++;
				maxn=i;
			}
		}
	}
	cout<<sum;
	return 0;
}
