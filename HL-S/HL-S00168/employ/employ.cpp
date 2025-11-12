#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	int n,m;
	cin>>n>>m;
	string nan;
	cin>>nan;
	vector<int>pation(501);
	vector<int>pation2(501);
	for(int i=0;i<501;i++){
		pation[i]=0;
	}
	for(int i=0;i<501;i++){
		pation2[i]=0;
	}
	for(int i=0;i<n;i++){
		int u;
		cin>>u;
		pation[u]++;
		pation2[u]++;
	}
	long long luobang=0;
	int begin=1;
	for(int i=0;i<n;i++){
		if(nan[i]=='0'){
			for(int oppo=begin;oppo<=500;oppo++){
				if(pation[oppo]){
					luobang++;
					pation[oppo]--;
					if(luobang>=oppo){
						begin=oppo+1;
						luobang+=pation[oppo];
						pation[oppo]=0;
					}
					break;
				}
				
			}
			
		}
		else{
			for(int oppo=begin;oppo<=500;oppo++){
				pation[oppo]--;
			}
		}
		if(n-luobang<m){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=500;i++){
		if(pation2[i]){
			ans*=pation2[i]%MOD;
		}
	}
	cout<<ans;
	return 0;
}