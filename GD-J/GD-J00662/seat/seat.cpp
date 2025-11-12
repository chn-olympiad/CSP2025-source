#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[110],ans,b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	b=n*m;
	for(int i=1;i<=b;i++)cin>>a[i];
	ans=a[1];
	sort(a+1,a+b+1,cmp);
	if(n==1&&m==1)cout<<"1 1";
	else if(n==1){
		for(int i=1;i<=m;i++){
			if(a[i]==ans){
				cout<<i<<' '<<1;//，第i行 第一列
				return 0;
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]==ans){
				cout<<1<<' '<<i;//第一列，第i行 
				return 0;
			}
		}
	}
	else if(n==2&&m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==ans){
				if(i==1)cout<<"1 1";
				if(i==2)cout<<"1 2";
				if(i==3)cout<<"2 2";
				if(i==4)cout<<"2 1";
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
