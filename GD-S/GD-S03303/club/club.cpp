#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10010][4];
int numa,numb,numc;
int F(int x){
	if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]){
		return 1;
	}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]){
		return 2;
	}else{
		return 3;
	}
}
int S(int x){
	if(a[x][1]>a[x][2]&&a[x][1]>a[x][3]){
		if(a[x][2]>a[x][3])return 2;
		else return 3;
	}else if(a[x][2]>a[x][1]&&a[x][2]>a[x][3]){
		if(a[x][1]>a[x][3])return 1;
		else return 3;
	}else{
		if(a[x][2]>a[x][1])return 2;
		else return 1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		numa=0,numb=0,numc=0;
		int summ=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				numa++;
				summ+=a[i][1];
			}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				numb++;
				summ+=a[i][2];
			}else{
				numc++;
				summ+=a[i][3];
			}
		}
		if(numa<=n/2&&numb<=n/2&&numc<=n/2){
			cout<<summ<<endl;
		}else{
			bool k[10010];
			int num[4]={0},ans=0;
			for(int i=1;i<=n;i++){
				int c=F(i);
				if(num[c]!=n/2){
					num[c]++;
					ans+=a[i][c];
				}else{
					int minn=100000,kl=1;
					for(int j=1;j<=i;j++){
						if(F(j)!=c||k[j]==1)continue;
						if(a[j][F(j)]-a[j][S(j)]<minn){
							minn=a[j][F(j)]-a[j][S(j)];
							kl=j;
						}
					}
					ans=ans-minn+a[i][c];
					k[kl]=1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 

