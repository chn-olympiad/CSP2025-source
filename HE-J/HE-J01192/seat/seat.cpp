#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num=2,now,ans,ans2;
int a[1000];
int b[100][100];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)now=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	b[1][1]=a[1];
	int i=1,j=1;
	while(num<=n*m){
		if(b[i+1][j]==0&&(i+1)<=n){
		b[i+1][j]=a[num];
		i++;
		}
		else if(b[i-1][j]==0&&(i-1)>0){
		b[i-1][j]=a[num];
		i--;	
		}
		else if(b[i][j+1]==0&&(j+1)<=m){
		b[i][j+1]=a[num];
		j++;	
		}
		num++;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==now){
			ans=j,ans2=i;	
			break;
			}
		}
		if(ans&&ans2)break;
	}
	cout<<ans<<" "<<ans2<<endl;
	return 0;
}
