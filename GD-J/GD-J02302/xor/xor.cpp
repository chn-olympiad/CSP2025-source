#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
long long n,k,ans,a[500010],c[500010];
map<long long,bool>m; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int j=l;j<=n;j++){
			if((c[j-l]^c[j])==k){
				int flag=1;
				for(int h=j-l+1;h<=j;h++){
					if(m.find(h)!=m.end()){
						flag=0;
						break;
					}
				}
				if(flag){
					ans+=1;
					for(int h=j-l+1;h<=j;h++){
						m[h]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
