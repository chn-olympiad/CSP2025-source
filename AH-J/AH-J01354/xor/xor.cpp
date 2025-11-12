#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100010],ans,q,p[10000][2],id,b[100010];
bool pd(int x,int y){
	for(int i=x;i<=y;i++) if(b[i]==1) return false;
	for(int i=x;i<=y;i++) b[i]=1;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j==i) q=a[i];
			else q^=a[j];
			if(q==k&&pd(i,j)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
