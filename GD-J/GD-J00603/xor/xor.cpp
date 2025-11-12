#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int a[N],numx[29],numy[29],res[29];
int orx(int x,int y){
	for(int i=1;i<=29;i++){
		numx[i]=0;
		numy[i]=0;
	}
	int cntx=0,cnty=0;
	while(x!=0){
		cntx++;
		numx[cntx]=x%2;
		x/=2;
	}
	while(y!=0){
		cnty++;
		numy[cnty]=y%2;
		y/=2;
	}
	int num=max(cntx,cnty);
	for(int i=1;i<=num;i++){
		if((numx[i]==0)&&(numy[i]==0)) res[i]=1;
		if((numx[i]==0)&&(numy[i]==1)) res[i]=1;
		if((numx[i]==1)&&(numy[i]==0)) res[i]=1;
		if((numx[i]==1)&&(numy[i]==1)) res[i]=0;
	}
	int r,j=1;
	for(int i=1;i<=num;i++){
		r+=(j*res[i]);
		j*=2;
	}
	cout<<"";
	return r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxn=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k1=a[i],cnt=0;
		for(int j=i;j<=n;j++){
			if(k1==k){
				cnt++;
				k1=a[j+1];
				continue;
			}
			else k1=orx(k1,a[j+1]);
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn<<endl;
	return 0;
}
