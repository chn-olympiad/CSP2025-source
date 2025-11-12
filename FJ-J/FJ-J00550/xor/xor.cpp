#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[500006],c[500006];
bool b[500006];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int shu=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			shu++;
			b[i]=1;
		} 
	}
	for(int i=1;i<n;i++){
		if((a[i]^a[i+1])==k&&b[i]==0&&b[i+1]==0){
			shu++;
			b[i]=1;
			b[i+1]=1;
		}
	}
	for(int i=1;i<n-1;i++){
		if((a[i]^a[i+1]^a[i+2])==k&&b[i]==0&&b[i+1]==0&&b[i+2]==0){
			shu++;
			b[i]=1;
			b[i+1]=1;
			b[i+2]=1;
		}
	}
	for(int i=1;i<n-2;i++){
		if((a[i]^a[i+1]^a[i+2]^a[i+3])==k&&b[i]==0&&b[i+1]==0&&b[i+2]==0&&b[i+3]==0){
			shu++;
			b[i]=1;
			b[i+1]=1;
			b[i+2]=1;
			b[i+3]=1;
		}
	}
	for(int i=1;i<n-3;i++){
		if((a[i]^a[i+1]^a[i+2]^a[i+3]^a[i+4])==k&&b[i]==0&&b[i+1]==0&&b[i+2]==0&&b[i+3]==0&&b[i+4]==0){
			shu++;
			b[i]=1;
			b[i+1]=1;
			b[i+2]=1;
			b[i+3]=1;
			b[i+4]=1;
		}
	}
	cout<<shu;
	return 0;
}
	
