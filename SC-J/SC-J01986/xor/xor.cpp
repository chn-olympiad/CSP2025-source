#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,k,a[maxn],c[maxn],ans,d[maxn];
bool b[maxn];


signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now,x;
	for(int i=1;i<=n;i++){
		x=0;
		now=0;
		for(int j=i;j<=n;j++){
			now=x^a[j-i];
			now=now^a[j];			
			if(j==i){
				d[i]=d[i-1]^a[i];
				now=d[i];
			} 
			if(now==k){
				bool flag=0;
				for(int q=j-i+1;q<=j;q++){
					if(b[q]==1){
						flag=1;
					}
				}
				if(flag==0){
					ans++;
					for(int q=j-i+1;q<=j;q++){
						b[q]=1;
					}
				}
			}
			x=now;
		}
	}
	cout<<ans;
	return 0;
}