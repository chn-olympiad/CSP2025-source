#include<bits/stdc++.h>
using namespace std;
int cj[500001],xorr[500001],ans,minn;
map<int,vector<int> > nm;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	nm[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>cj[i];
	    xorr[i]=(cj[i]^xorr[i-1]);
	    nm[xorr[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
//		cout<<xorr[i]<<':'; 
		int ym=(xorr[i]^k),sz=nm[ym].size();
		if(i<minn) continue;
		int r=510000,m=262144;
		while(sz>0&&m>0){
			if((r-m)>=sz) r-=m;
			else if(r-m>=0&&nm[ym][r-m]>=minn) r-=m;
			m/=2;
		}
		if(r<505000&&r<sz&&nm[ym][r]<i){
//		cout<<nm[ym][r]<<endl;
		minn=i;
		ans++;
	    }
//		else cout<<"null\n";
	}
	cout<<ans;
	return 0;
}
