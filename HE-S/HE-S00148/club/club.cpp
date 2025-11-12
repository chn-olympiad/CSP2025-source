#include<bits/stdc++.h>
using namespace std;
#define N 1000000;
int a,b;
return a>b;
int a[N][4];
int n,sum[4],b[3];

int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)

	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		a[i][1]=b[1];a[i][2]=b[2];a[i][3]=b[3];
		a[i][4]=b[1]-b[2];
		a[i][5]=b[2]-b[3];
	sort(b+1,b+4,myd);
	a[i][7]=-1;
	for(int j=0;j<4;j++){
		if (a[i][j]>a[i][7]){
			a[i][7]=a[i][j];
			a[i][6]=j;
		}else if(a[i][j]<=n/2){
			int cnt=0;
			cnt=max(a[i][1],a[i][2],a[i][3]);
			int ans=0;
			ans=cnt+ans;
			cout<<ans;
		}
	}
			}
		}
		return 0;
	}

