#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[10005];
bool cheeky(int l,int r){
	int num=0,maxn=0;
	for(int i=1;i<=n;i++){
		num+=a[i];
		maxn=max(a[i],maxn);
	} 
	if(num>=3 and maxn*2<num){
		return 1;
	}
	return 0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);	
	cin.tie(0);                                                                                                                                              
	cout.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){                                                                                              
		for(int j=1;j<=n;j++){
			if(cheeky(i,j))ans++;
		}
	}
	cout<<ans%mod;                                	                                                                                       
	return 0;                                                             
}                           
                                    