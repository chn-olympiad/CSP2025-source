#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,cnt;
int a[N],b[N][N],a1[8*N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<n;i++){
    	cout<<a[i];
    	for(int j=8*i;j>=8*(i-1);j--){
    		
		}
	}
	int maxx=-1e9+1; 
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			cnt=0;
			for(int i=l;i<=r;i++){
			}maxx=max(maxx,cnt);
		}
	}
	cout<<maxx;
	return 0;
} 
