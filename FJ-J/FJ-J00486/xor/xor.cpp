#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
int ans;
bool flag[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(k==1){
		for(int i=1;i<=n;i++) if(a[i]==1) ans++; 
	}
	else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1&&!flag[i]){
				ans++;
				flag[i+1]=true;
			}
		}
	}
	else for(int i=1;i<=n;i++) if(a[i]==k) ans++;
	cout<<ans;
	return 0;
}
