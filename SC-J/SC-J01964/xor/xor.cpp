#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
bool b[N];
int js(int x,int y){
	int res=0;
	int now=1;
	while(!(x==0 && y==0)){
		int xx=x%2;
		int yy=y%2;
		x/=2; y/=2;
		if(xx!=yy) res+=now;
		now*=2;
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
//	cout<<js( 2,1);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	int g=2;
	while(g<=n-ans){
		for(int i=0;i<n;i++){
			int tmp=0;
			bool flag=0;
			for(int j=0;j<g;j++){
				if(i+g-1<n){
					if(b[i+j]==0){
//						cout<<tmp<<'\n';
						tmp=js(tmp,a[i+j]);
						flag=1;
					}
					else break;		
				}
				else break;		
			}
			if(tmp==k && flag){
//				cout<<i<<'\n';
				ans++;
				for(int j=0;j<g;j++) b[i+j]=1;
			}
		}
		g++;
	}
	cout<<ans;
	return 0;
}