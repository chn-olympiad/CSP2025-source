#include<iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,b[12],a[100005][2],c[100005],g[12][1005],o[12],mina=10000000,mind,sum,minc=10000000;
	cin>>n,m,k;
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1]>>c[i];
		if(c[i]<mina){
			mina=c[i],mind=i;
		}
	}
	for(int i=0;i<k;i++){
		sum=0;
		cin>>o[i];
		sum+=o[i];
		for(int j=0;i<n;j++){
			cin>>g[i][j];
			if(!(j==a[mind][0]||j==a[mind][1]))sum+=g[i][j];
		}
		b[i]=sum;
		if(b[i]<minc){
			minc=b[i];
		}
	}
	cout<<mina+minc;
	return 0;
}
