#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N],s[N];
int n,k,ans=-1,b,c,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		l=i,r=i;
		if(a[l]^a[r]==k) {
			ans++;
			continue;
		}
		else{
			m=l;
			s[l]=a[l];
			for(r=m+1;r<=n;r++){
				s[r]=s[r-1]^a[r];
				if(s[r]==k){
					ans++;
					if(r==n){
						cout<<ans;
						return 0;
					}else{
					    i=r+1;
					    break;
					}
				}
			}
		}
	}cout<<ans;
	return 0;
}
