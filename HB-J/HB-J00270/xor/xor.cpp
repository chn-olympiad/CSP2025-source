#include <bits/stdc++.h>
using namespace std;
int yh(int x,int y){
	int zz=0;
	string xx,yy,ss;
	while(x>0){
		xx=char(x%2+48)+xx;
		x/=2;
	}
	while(y>0){
		yy=char(y%2+48)+yy;
		y/=2;
	}
	int xxx=xx.size(),yyy=yy.size();
	int zzz=max(xxx,yyy),uuu=min(xxx,yyy);
	for(int i=0;i<zzz;i++){
		if(i<uuu){
			if(xx[i]==yy[i]){
				ss='0'+ss;
			}else{
				ss='1'+ss;
			}
		}
		else{
			if(zzz==xxx){
				if(xx[i]=='1') ss='1'+ss;
				else ss='0'+ss;
			}else{
				if(yy[i]=='1') ss='1'+ss;
				else ss='0'+ss;
			}
		}
	}
	int z=1;
	for(int i=0;i<ss.size();i++){
		zz+=z*(int(ss[i])-48);
		z=z*2;
	}
	
	return zz;
}
long long n,k,a[5000001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[i];
			for(int ii=i+1;ii<=j;ii++){
				x=yh(x,a[ii]);
			}
			if(x==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
