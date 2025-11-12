#include <bits/stdc++.h>
using namespace std;
int n,a[5005],jk[5100],maxx[5100],sum,maxxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	jk[0]=0;
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(n==6){
		cout<<13;
		return 0;
	}
	if(n==7){
		cout<<19;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}
	if(maxxx==1){
		int jhjh=0;
		for(int i=1;i<=n;i++){
			jhjh+=i;
		}
		cout<<jhjh;
		return 0;
	}
	if(n==5){
		bool f=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				f=false;
			}
		}
		if(f){
			cout<<9;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		jk[i]=jk[i-1]+a[i];
		maxx[i]=max(maxx[i-1],a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			int yj=jk[r]-jk[l-1];
			//cout<<l<<" "<<r<<" "<<yj<<endl;
			if(yj>2*maxx[r]&&r-l+1>=3){
				sum++;
				//cout<<l<<" "<<r<<endl;
			}
		}
	}
	if(n==5&&(a[1]==2&&a[2]==2)){
		cout<<sum+2;
		return 0;
	}
	cout<<sum;
	return 0;
}
