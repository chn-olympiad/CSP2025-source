#include<bits/stdc++.h>
using namespace std;
long long n,m,ng[501],zc[501],mg,rs,jl[501],da;
bool bj[501];
char nd[501];
void mj(long long bh){
	if(bh==n+1){
		mg=0;
		rs=0;
		for(int i=1;i<=n;i++){
			if(mg<zc[jl[i]]){
				if(ng[i]==0){
					mg++;
				}
				else{
					rs++;
				}
			}
			else{
				mg++;
			}
		}
		if(rs>=m){
			da++;
			da%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			jl[bh]=i;
			bj[i]=1;
			mj(bh+1);
			bj[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>nd;
	for(int i=1;i<=n;i++){
		if(nd[i-1]=='0'){
			ng[i]=0;
		}
		else{
			ng[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>zc[i];
	}
	mj(1);
	cout<<da<<endl;
	return 0;
}
