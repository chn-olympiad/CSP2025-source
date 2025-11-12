#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+10;
int a[N];
int s[N];
int o_r[N];

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=a[i]^s[i-1];
	}
	int cnt=0;
	int mxr=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int ans=s[r]^s[l-1];
			if(ans==k){
				bool f=0;
				int p=1;
				for(int i=cnt;i>=1;i--){
					if(l<=o_r[i]){
						f=1;
					}else{
						p=i+1;
						break;
					}
				}
				if(!f){
					cnt++;
					o_r[p]=r;
				}
			}
		}
	}
	cout << cnt;
	
	return 0;
}
