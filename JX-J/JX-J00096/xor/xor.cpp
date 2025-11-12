#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],l,r,t,c,s;
map <int,int> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int d=sum[j]^sum[i-1];
			if(d==k){
				//cout <<i<<" "<<j<<endl;
				m[j]=i;
			}
		}
	}
	for(auto x:m){
		c++;
		if(c==1) t=x.first,s++;
		else{
			if(x.second>t) t=x.first,s++;
		}
	}
	cout <<s;
	return 0;
}
