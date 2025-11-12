#include<bits/stdc++.h>
using namespace std;
const long long int d=998244353;
int n;
int a[5005],b[5005];
long long int ans;

void sp(){
	for(int i=3;i<=n;i++){
		long long int tmp=1,p=1;
		while(p<=i){
			tmp*=n-p+1;
			tmp/=p;
			p++;
			tmp%=d;
		}
		//cout<<tmp<<endl;
		ans+=tmp;
	}
	cout<<ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>n;
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		int pos=max(max(max(x,y),max(y,z)),max(x,z));
		if(pos*2<x+y+z) cout<<1;
		else cout<<0;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[b[i]]++;
	}
	sort(b+1,b+n+1);
	if(a[1]==n){
		sp();
		return 0;
	}
	return 0; 
}
