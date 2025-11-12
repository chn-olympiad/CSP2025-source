#include <bits/stdc++.h>
using namespace std;
int yh(int a,int b){
	if(a==1&&b==1) return 0;
	if(a==1&&b==0) return 1;
	if(a==0&&b==1) return 1;
	if(a==0&&b==0) return 0;
}
int n,k;
int a[200005];
int ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(yh(a[i],a[i+1])==k) {
			ans++;
			i++;	
		}
	}
	cout<<ans;
    return 0;
} 
