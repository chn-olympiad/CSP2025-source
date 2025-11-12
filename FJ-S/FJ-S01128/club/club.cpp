#include <bits/stdc++.h>
using namespace std;
int a[500009][4],b[4][500009],maxi,maxj,z=1,ans[11];
int main(){
	cout.tie(0);
	cin.tie(0);
	long long t,n;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){	
	maxi=0,maxj=0;
	long long l[4]={0,1,1,1};
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[i][j]=0;
			b[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		long long max=1;
		cin>>a[i][2];
		if(a[i][2]>=a[i][max])max=2;
		cin>>a[i][3];
		if(a[i][3]>=a[i][max])max=3;
		b[max][l[max]]=i;
		l[max]++;
	}
	if(l[1]-1>n/2||l[2]-1>n/2||l[3]-1>n/2){
	int maxm=0;
	for(int x=1;x<=3;x++){
		if(l[x]-1>n/2){
			for(int i=1;i<=l[x]-1;i++){
				for(int j=i;j<=l[x];j++){
					if(a[b[x][i]][x]<a[b[x][j]][x])swap(b[x][i],b[x][j]);
				}
			}
			while(l[x]-1>n/2){
				maxm=0;
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						if(i==1&&j==1)continue;
					    int sum=a[b[x][l[x]-1]][i]+a[b[x][l[x]-2]][j];
						if(sum>maxm){
							maxm=sum;
							maxi=i;
							maxj=j;
					        if(maxi!=x&&maxi>0){
							b[maxi][l[maxi]]=b[x][l[x]-1];
							b[x][l[x]-1]=0;
							l[maxi]++;
							l[x]--;
							}
						 	if(maxj!=x&&maxi>0){
							b[maxj][l[maxj]]=b[x][l[x]-2];
							b[x][l[x]-2]=b[x][l[x]-1];
							b[x][l[x]-1]=0;
							l[maxj]++;
							l[x]--;
							}
						}
					}
				}
			}
		}
	}
}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++)ans[z]+=a[b[i][j]][i];
	}
	z++;
}
	for(int i=1;i<=z-1;i++)cout<<ans[i]<<endl;
	return 0;
}
