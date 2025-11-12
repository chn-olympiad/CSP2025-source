#include <bits/stdc++.h>
using namespace std;
bool a[50005],b[50005];
int n;
bool k;
int ans;
bool xorn(bool x,bool y){
	if(x==y) return 0;
	if(x!=y) return 1; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			b[i]=1;
		}
	}
	for(int i=0;i<n-1;i++){
		if(b[i]==0&&b[i+1]==0&&xorn(a[i],a[i+1])==k){
			ans++;
			b[i]=1;
			b[i+1]=1; 
		}
	}
	cout<<ans;
} 
