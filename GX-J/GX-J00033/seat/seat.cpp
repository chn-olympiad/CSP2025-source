#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int j=1;
	for(int i=2;i<=n*m;i++)if(a[1]<a[i])j++;
	if(j/m==0&&j<=m)cout<<"1 "<<j;
	else{
		if((j%m==0&&(j/m)%2==0)||((j/m)%2==1&&j%m!=0)){
			if(j%m==0)cout<<j/m<<" "<<1;
			else if(m==2&&(j/m)%2==1&&j%m!=0)cout<<j/m+1<<" "<<m;
			else if((j/m)%2==1&&j%m!=0)cout<<j/m+1<<" "<<m-j%m;
			else cout<<j/m<<" "<<m-j%m;
		}else{
			if(j%m==0)cout<<j/m<<" "<<m;
			else if((j/m)%2==0)cout<<j/m+1<<" "<<j%m;
			else cout<<j/m<<" "<<j%m;
		}
	}
	return 0;
}
