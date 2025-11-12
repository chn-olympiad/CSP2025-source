#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],s[24][24],xx,yy,c=1,xm;
bool p;
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
	xm=a[1];
	sort(a+1,a+n*m+1,cmp);
	xx=1;
	yy=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[xx][i]=a[c];
			if(a[c]==xm){
				cout<<i<<" "<<xx;
				return 0;
			}
			if(p==0){
				xx++;
			}else{
				xx--;
			}
			c++;
		}
		if(i%2!=0){
			xx=n;
			p=1;
		}else{
			xx=1;
			p=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
