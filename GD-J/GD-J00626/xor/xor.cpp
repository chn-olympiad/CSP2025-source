#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],b[1000005],sum;
int x=0,y=0;
map <int,int> p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	while(y<n){
		y++;
		int d=(b[y]^k);
		int t=p[d]+1;
		p[b[y]]=y;
		if(t==1&&b[y]!=k) continue; 
		if(t>x){
			x=y;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
