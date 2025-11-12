#include<bits/stdc++.h>
using namespace std;
const int N = 500+5; 
int a[N];
int b[N];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=0;i<n;i++){
		scanf("%1d",&a[i]);
		if(a[i]!=1) f=0;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int ans=1;
	if(f){
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
