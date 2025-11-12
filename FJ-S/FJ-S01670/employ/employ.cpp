#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],ans,w;
bool pd[1000];
string b;

int v(int k){
	w=1;
	for(int i=2;i<=k;i++) w*=i;
	return w;
}
void e(int i,int k,int q){
	pd[i]=1;
	if(b[k+q]=='1'&&a[i]>q) k++;
	else q++;
	if(k==m){
		ans+=v(n-(k+q));
		pd[i]=0;
		return;
	}
	if(m-k>n-q-k){
		pd[i]=0;
		return;
	}
	for(int j=1;j<=n;j++){
		if(pd[j]==1) continue;
		e(j,k,q);
	}
	pd[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=18){
		for(int i=1;i<=n;i++) e(i,0,0);
	}else if(m==1){
		int ip=10000;
		for(int i=0;i<n;i++){
			if(b[i]=='1'){
				ip=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>ip) ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
20 1
01101111011101111111
1 1 1 1 0 1 1 1 1 1 2 1 1 1 3 1 1 1 1 1 
*/

