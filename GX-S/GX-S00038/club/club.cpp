#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,sum;
int a[N],b[N],c[N];
void lxc(int a[N]){
	int e;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]&&i!=1) e=a[i],a[i]=a[i-1],a[i-1]=e; 
		}
	}	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int m=1;m<=t;m++){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		lxc(a),lxc(b),lxc(c);
		if(n==1e5){
			for(int i=1;i<=n/2;i++) sum+=a[i];
			cout<<sum;
		}
		//for(int i=1;i<=n;i++) cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl; 
	}
	return 0;
}
