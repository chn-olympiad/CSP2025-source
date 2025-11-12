#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int cnt = 0;
	for(int l = 1;l<=n;l++){
		int m = a[l];
		if(m==k) cnt++;
		else{
			int r;
			for(r = l+1;r<=n;r++){
				m^=a[r];
				if(m==k){
					break;
				}	
				
			}
			cnt++;
			l = r+1;
		}
	}
	cout<<cnt;
	return 0;
}
