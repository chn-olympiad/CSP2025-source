#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
char a[100005];
int c[100005];
bool flaga=1;
ll ans=1;
int ccc;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ccc=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!='1') {
			flaga=0; 
		}
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			ccc++;
		}
	}
	if(flaga){
		n-=ccc;
		for(int i=n;i>=m+1;i--){ 
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}

