#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5*100000+5],n,k,ans;
//vector < vector < int > > v;
short v[5*1000+5][5*1000+5];
bool pd(int x,int c){
	int kil=0;
	for(int i=x;i<=x-c+1;i--){
		for(int j=1;j<=c;j++){
			if(v[i][j]==k){
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(flag){
		if(k==0){
			cout<<n-1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==1 and a[j]==k) {v[j][i]=k;ans++;}
			else {v[j][i]=a[j];}
			if(v[j-1][i-1]^a[j]==k){
				v[j][i]=k;
				if(pd(i,j)) {ans++;}
			}	
		}
	}
	cout<<ans;
}