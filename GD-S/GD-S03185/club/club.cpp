#include<bits/stdc++.h>
#include<random>
#define int long long
using namespace std;
int t,n,haogan[100007][5],sum=0;
int apeople=0,bpeople=0,cpeople=0;
int asum=0,bsum=0,csum=0;
bool bijiao(int a){
	if(a<=n/2)return true;
	return false;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int q=1;q<=n;q++){
			for(int z=1;z<=3;z++){
				cin>>haogan[q][z];
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++){
				if(bijiao(apeople)&&bijiao(bpeople)&&bijiao(cpeople)){
					  
				}else{
					continue;
				}
			}
		}
	}
	return 0; 
}
