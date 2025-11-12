#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500100],s[500100];
bool st[500100];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1] xor a[i];
	}
	int cnt=0;
	for(int w=0;w<n;w++){
		for(int j=1+w;j<=n;j++){
			int i=j-w;
			int q=s[j] xor s[i-1];
			if(q==k&&st[i]==0&&st[j]==0){
				bool l=0;
				for(int t=i;t<=j;t++){
					if(st[t]==1){
						l=1;
					}
				}
				if(l==0){
					cnt++;
					for(int t=i;t<=j;t++){
						st[t]=1;
					}
				}
				
			}
		}
	}
	cout<<cnt;
	return 0;
} 
/*
s[i] xor s[j] = k
s[i] xor k = s[j]
*/
