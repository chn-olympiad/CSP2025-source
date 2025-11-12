#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int n;
int maxx;
void f(int a1,int b,int c,int ans,int num){
	if(num>n&&a1+b+c==n){
		maxx=max(maxx,ans);
//		cout<<ans<<" ";
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&a1<(n/2)){
			f(a1+1,b,c,ans+a[num][i],num+1);			
		}
		if(i==2&&b<(n/2)){
			f(a1,b+1,c,ans+a[num][i],num+1);
		}
		if(i==3&&c<(n/2)){
			f(a1,b,c+1,ans+a[num][i],num+1);

		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	while(k--){	
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		maxx=-1e9;
		f(0,0,0,0,1);
		cout<<maxx<<endl;
	}
	return 0;
}
