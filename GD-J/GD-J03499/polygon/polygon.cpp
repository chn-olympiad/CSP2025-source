#include<bits/stdc++.h> 
using namespace std;
long long n,a[5009],ans,al,b[5009],c[5009];
void p(int nn,int ho,int ma,int w){
	if(nn==0){
		int he;
		he=al;
		for(int i=1;i<=w;i++){
			he-=a[b[i]];
		}
		int g;
		for(int i=n;i>=1;i--){
			if(c[i]==0){
				g=i;
				break;
			}
		}
		if(he>a[b[g]]*2){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=ho;i<=ma;i++){
		b[nn]=i;
		c[i]=1;
		p(nn-1,i+1,ma+1,w);
		c[i]=0;
	}
}
int main(){
	freopen("polygon.in ","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		al+=a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=3;i<=n;i++){
		int o;
		o=n-i;
		p(o,1,i+1,o);
	}
	cout<<ans;
}
