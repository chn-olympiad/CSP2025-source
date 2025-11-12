#include<bits/stdc++.h>
using namespace std;
int n,m,ansx,ansy,p,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tmp1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp1){
			p=i;
			break;
		}
	}
	int tmp2=p/n,tmp3=p%n;
	if(tmp3==0){
		ansx=tmp2;
		if(tmp2%2==0) ansy=1;
		else ansy=n;
	}
	else{
		ansx=tmp2+1;
		if(tmp2%2==0){
			ansy=tmp3;
		}
		else{
			ansy=n-tmp3+1;
		}
	}
	cout<<ansx<<' '<<ansy<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
