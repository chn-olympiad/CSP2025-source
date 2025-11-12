#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4],maxx = -1;
void f(int now,int yi,int er,int san,int sum){
	cout<<now<<endl;
	if(now==n){
		if(sum>maxx){
			maxx  =sum;
		}
		return;
	}
	for(int i = 1;i<=3;i++){
		if(i==1&&yi<n/2){
			f(now+1,yi+1,er,san,sum+a[now][i]);
		}
		if(i==2&&er<n/2){
			f(now+1,yi,er+1,san,sum+a[now][i]);
		}
		if(i==3&&san<n/2){
			f(now+1,yi,er,san+1,sum+a[now][i]);
		}
	}
	
}
int main(){
	freoepn("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	f(1,0,0,0,0);
	cout<<maxx;
	return 0;
}
