#include <bits/stdc++.h>
using namespace std;
int vis[15][15];
int a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ans1=1,ans2=1;
	bool b=1;
	for(int i=1;a[i]!=y;i++){
		if((ans1==n&&b==1)||(ans1==1&&b==0)){
			if(ans1==n&&b==1){
				ans2++;
				b=0;
			}else if(ans1==1&&b==0){
				ans2++;
				b=1;
			}
		}else{
			if(b==1){
				ans1++;
			}else{
				ans1--;
			}
		}
	}
	cout<<ans2<<' '<<ans1;
	return 0;
}

