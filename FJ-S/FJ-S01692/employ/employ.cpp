#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],c[504],k,l,u;
bool bo[1145],po[111];
void dps(int x){
	cout<<1;
	if(l==n){
		if(x-a[x-1]>=m){
			u++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x]>b[i]){
			po[i]=1;
			l++;
		}
		if(bo[i]==0&&po==0){
			bo[i]=1;
			l++;
			dps(x+1);
			l--;
			bo[i]=0;
		}
		if(a[x]<=b[i]){
			po[i]=0;
			l--;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1];
		cin>>ch;
		if(ch=='0'){
			a[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(a[n]==0){
		long long o=1;
		for(int i=1;i<=n;i++){
			o=o*i%998244353;
		}
		cout<<o;
	}else if(m>n-a[n]){
		cout<<0;
	}else{
		dps(1);
		cout<<u;
	}
	
	return 0;
}
