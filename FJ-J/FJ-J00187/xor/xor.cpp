#include<bits/stdc++.h>
using namespace std;
int n,k,l[500005],r[500005],g,o,h[500005],v;
long long a[500005];
bool b[500005];
int main(){
	cin>>n>>k;
 	for(int i=1;i<=n;++i)
 		cin>>a[i];
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			l[i]=i,r[i]=i,b[i]=1;
			++o;
		}else{
			g=a[i];
			for(int j=i+1;j<=n;++j){
				g=g^a[j];
				if(g==k){
					l[i]=i,r[i]=j,b[i]=1;
					++o;
					break;
				}
			} 
		} 
	}
	for(int i=1;i<=n;++i){
		if(b[i]==1){
			for(int j=l[i];j<=r[i];++j)
				++h[j];
		}
	}
	for(int i=1;i<=n;++i){
		if(b[i]==1){
			for(int j=l[i];j<=r[i];++j){
				if(h[j]>1){
					for(int u=l[i];u<=r[i];++u)
						h[u]--;
					++v;
					break;
				}
			}
				
		}
	}
	cout<<o-v;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	return 0;
} 
