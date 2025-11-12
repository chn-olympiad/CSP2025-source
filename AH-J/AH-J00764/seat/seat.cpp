#include<bits/stdc++.h>
using namespace std;
int a[110],n,R,ans[15][15],m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,cnt=1;
	while(cnt<=n*m){
		ans[x][y]=a[cnt];
		if(a[cnt]==R){
			cout<<x<<" "<<y;
			return 0;
		}
		cnt++;
		if(x%2==1){
			y+=1;
			if(y==n+1){
				x+=1;
				y=n;
			}
		}else{
			y-=1;
			if(y==0){
				x+=1;
				y=1;
			}
		}
		
	}
	return 0;
}
