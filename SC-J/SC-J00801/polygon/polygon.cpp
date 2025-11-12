#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n;
int Mantra;
int gun[5005];
bool aflag=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gun[i];
		if(gun[i]!=1){
			aflag=1;
		}
	}if(n==3){
		if(gun[1]+gun[2]+gun[3]>max(gun[1],max(gun[2],gun[3]))*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	return 0;
}