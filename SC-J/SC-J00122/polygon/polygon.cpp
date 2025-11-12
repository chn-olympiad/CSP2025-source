#include<bits/stdc++.h>
using namespace std;
int a[5005]={0};
int sum1=0;
int n;
void fid(int sum,int m,int maxx,int d){
	if(m>=3&&(sum>(2*maxx))){
		sum1++;
	}
	m++;
	for(int i=d;i<=n;i++){
		int p=sum;
		sum+=a[i];
		int o=maxx;
		maxx=max(maxx,a[i]);
		fid(sum,m,maxx,i+1);
		sum=p;
		maxx=o;
	}
	return ;
}
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	fid(0,0,0,1);
	cout <<sum1%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}