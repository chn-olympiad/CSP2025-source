#include <bits/stdc++.h>
using namespace std;
long long n,m,ans[15][15],a[105];
long long num;

bool cmp(int ki,int ci){
	return ki>ci;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			num=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		ans[x][y]=a[i];
		if(x==1&&y%2==0||x==n&&y%2==1){
			y++;
		}
		else if(y%2==1)x++;
		else if(y%2==0)x--;
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<ans[i][j]<<" ";
			if(ans[i][j]==num){
				//cout<<endl<<ans[i][j]<<endl;
				cout<<j<<" "<<i;
			}
		}
		//cout<<endl;
	}
	
	
	return 0;
}
