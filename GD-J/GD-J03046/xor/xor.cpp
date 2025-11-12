#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
long long a[maxn],b[maxn],c[maxn],k,n,ans;
bool flag=true;
int main(){
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	int sr=1,tmp=0;
	for(int l=1,r=l;l<=2*n+1,r<=2*n+1;l++,r++){
		if(r>n||l>n){
			sr++;
			if(sr>n) break;
			l=1;r=sr;
		}
		if(abs(b[r]-b[l-1])==k){
			for(int i=l;i<=r;i++){
				if(c[i]==-1){
					flag=0;
					break;
				}
			}
			if(flag){
				ans++;
				for(int i=l;i<=r;i++) c[i]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}

