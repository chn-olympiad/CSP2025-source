#include <iostream>
#include <algorithm>
using namespace std;

int t,n,mz=0;
int ar=0,br=0,cr=0;
int a[100001][4],b[100001],r[50001][4],r1[1][4];
int mmax(int i){
	int max=0;
	for(int j=1;j<=3;j++){
		if(a[i][j]>max){
			max=a[i][j];
			r[i][j]=max;
		}
	}
	mz+=max;
	return mz;
}
int main(){
	int k,i,j=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(k=0;k<t;k++){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++) cin>>a[i][j];
		}
		for(i=1;i<=n;i++){
			mmax(i);
		}
		cout<<mz<<endl;
		mz=0;
	}
}
