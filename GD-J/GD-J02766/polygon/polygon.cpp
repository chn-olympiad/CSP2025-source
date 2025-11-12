//3≤ n ≤5000；
//对于所有1≤i≤n,均有1≤ai≤5000
#include<bits/stdc++.h>
using namespace std;
int n,a[5050],cnt,s;
bool f[5050];
void p(int k,int sum,int maxn,int now){
	if(k>s){
		if(sum>maxn*2){
			cnt++;
		}
		return;
	}
	for(int i=now;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			p(k+1,sum+a[i],max(maxn,a[i]),i+1);
			f[i]=0;
		}
	}
	return;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		s=i;
		p(1,0,-1,1);
	}
	cout<<cnt%998244353<<'\n';
fclose(stdin);
fclose(stdout);
	return 0;
}
