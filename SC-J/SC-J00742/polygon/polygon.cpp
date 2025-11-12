#include<bits/stdc++.h>
using namespace std;
int a[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int tnt=0;
	int txt=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(maxn==1){
		cout<<(n*n-2)%998244353;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int strat=1;strat<=n-i;strat++){
			for(int end=strat+i;end<=n;end++){
				maxn=0;
				for(int j=strat;j<end;j++){
					txt+=a[i];
					maxn=max(maxn,a[i]);
				} 
				if(maxn*2<txt){
					tnt++;//cout<<txt<<" "<<maxn<<" "<<i<<" "<<strat<<" "<<end<<endl; 
				}
			} 
		}
	}
	cout<<tnt%998244353;
	return 0;
}