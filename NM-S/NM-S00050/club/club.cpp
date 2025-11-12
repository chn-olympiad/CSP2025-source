#include<bits/stdc++.h>
using namespace std;
int ren[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ren[i][1]>>ren[i][2]>>ren[i][3];
	}
	int rp=0,m=n;
	rp++;
	int f[4]={0,n-n/2,n-n/2,n-n/2};
    int sum=0;
	while(m--){
		int maxn=-1;
		int x,y;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(ren[i][j]>=maxn&&f[j]){
					maxn=ren[i][j];

					f[j]--;
					x=i;
					y=j;
				}
			}

		}
		sum+=maxn;
			maxn=-1;
            ren[x][1]=-2;
            ren[x][2]=-2;
            ren[x][3]=-2;
	}
	cout<<sum;
}



