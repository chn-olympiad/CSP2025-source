#include<bits/stdc++.h>//iloveu ljn&Six_flower,pls giveme mwreluck for RP++!!! 
//#include<cmath>
#define int long long//so dou want tostaywithme?
using namespace std;//i hope so,wecan help eachother,willthat become truth?
int n,k;//wishmea good luck---both csp and our future
bool k1=1,k2=2;
int a[500050];
//kmax=1e6+1e5
int cf[500050][22];
int pd[1100000][2],id;
int ans;
bool check(int x,int y){
	for(int i=1;i<=id;i++){
		if((pd[i][0]<=x&&x<=pd[i][1])||(pd[i][0]<=y&&y<=pd[i][1])||(x<=pd[i][0]&&pd[i][1]<=y)){
			return false;
		}
	}
	return true;
}
signed main(){
//	freopen("xor5.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>cf[i][0];
		if(cf[i][0]!=1){
			k1=0;
			if(cf[i][0]!=0){
				k2=0;
			}
		}
	}
	if(k1){
		cout<<n/2;
		return 0;
	}
	if(k2){
		if(k){
			if(k!=1){
				cout<<0;
				return 0;
			}
			int sam=0;
			for(int i=1;i<=n;i++){
				sam+=cf[i][0];
			}
			cout<<sam;
		}else{
			int sam=0;
			for(int i=1;i<=n;i++){
				if(cf[i][0]&&cf[i+1][0]){
					sam++;
					i=i+2;
				}
				if(!cf[i][0]) sam++;
			}
			cout<<sam;
		}
		return 0;
	}
	for(int j=1;j<=22;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			cf[i][j]=cf[i][j-1]^cf[i+(1<<(j-1))][j-1];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;i+(1<<j)-1<=n;j++){
//			cout<<i<<' '<<j<<' '<<cf[i][j]<<'\n';
//		}
//	}
	int now,t;
	for(int j=1;j<=n;j++){
		int la=n; 
		for(int i=n-j+1;i>=1;i--){
			if(i+j-1>la){
				continue;
			}
			now=cf[i][__lg(j)];t=i+(1<<(__lg(j)));
			while(t<=i+j-1){
//				cout<<114514;
				now=now^cf[t][__lg(i+j-t)];
				t=t+(1<<(__lg(i+j-t)));
			}
//			cout<<i<<' '<<j<<' '<<now<<'\n';
			if(now==k){
				if(check(i,i+j-1)){
					ans++;
					pd[++id][0]=i;
					pd[id][1]=i+j-1;
					la=i;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/
