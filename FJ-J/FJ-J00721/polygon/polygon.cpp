#include<bits/stdc++.h>
using namespace std;
long long sn,s,n,R=998244353,f[5010],a[5010];
void RQ(long long t,long long sf,long long sm,long long j){
	if(t>3&&sf>sm*2){
		s++;
		s%=R;
	}
	if(t>n) return;
	for(int i=j;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			RQ(t+1,sf+a[i],max(sm,a[i]),i);
			f[i]=0;
		}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) sn++;
	}
	if(sn==n){
		cout<<(n-2)%R<<endl;
		return 0;
	}
	RQ(1,0,0,1); 
	cout<<s%R<<endl;
	return 0;
}

