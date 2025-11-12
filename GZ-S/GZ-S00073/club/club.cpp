//GZ-S00073 安顺市第一高级中学 卢子墨 
#include<bits/stdc++.h>
#define MAXN 100010

using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,a[MAXN][4],mmax=0,b[MAXN];
	cin>>t;
	while(t--){
		cin>>n;
		int mid=n/2;
		for(long long i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(a[1][1]==0&&a[1][3]==0){
			for(int i=1;i<=n;i++){
			b[i]=a[i][2];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=mid;i++){
				mmax+=b[i];
			}
			cout<<mmax<<endl;
			mmax=0;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					a[i][1]=max(a[i][1],a[i][1+j]);
				}
			}
			for(int i=1;i<=n;i++){
				mmax+=a[i][1];
			}
			cout<<mmax<<endl;
		}
	}
		
	
/*	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}*/
	
	return 0;
} 
