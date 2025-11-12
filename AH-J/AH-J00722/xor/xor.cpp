#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],he=0,ans=0;
int YI(int x,int y){
	int xy=0,yy=0,an=0;
	double zhishu=0.0;
	while(x/2>0||y/2>0||x==1||y==1){
		xy=x%2;
		yy=y%2;
		if(xy!=yy){
			an+=pow(2,zhishu);
			zhishu++;
		}else{
			zhishu++;
		}
		x=x/2;
		y=y/2;
	}
	return an;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int l=1,r=n;
	int mid=(l+r)/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			if(i<mid){
				l=i+1;
			}else if(i>mid){
				r=i-1;
			}else{
				l=i;
			}
		}
	}
	he=a[l];
	for(int i=l;i<=r-1;i++){
		for(int j=i+1;j<=r;j++){
			he=YI(he,a[j]);
			if(he==k){
				ans++;
				l=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
