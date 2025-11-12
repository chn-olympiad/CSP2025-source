#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,a[N],sum,m=2;
bool b[N];
int www(int num,int sp,int z){
	if(sp==1) return z;
	int p=z;
	for(int i=1;i<sp;i++)
		p=p^a[num+i];
	if(p==k){
	sum++;
	b[num]=1;
	for(int i=1;i<sp;i++)
		b[num+i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) {
		b[i]=1;
		sum++;
		}
	}
	for(int i=m;i<=n-sum;i++){
		for(int j=1;j<=n;j++){
			if(b[j]==1) continue;
			www(j,i,a[j]);
		}
	}
	cout<<sum;
}