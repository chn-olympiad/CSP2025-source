#include<bits/stdc++.h>
using namespace std;
int a[101];
int b[101][101];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1];
	int z=n*m;
	sort(a+1,a+1+z,cmp);
	int g;
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			g=i;
			break;
		}
	}
	int xx=g/n;
	int yy=g%n;
	if(yy==0){
		if(xx%2==1){
			cout<<xx<<" "<<n;
		}
		else{
			cout<<xx<<" "<<1;
		}
	}
	else{
		xx++;
		if(xx%2==1){
			cout<<xx<<" "<<yy;
		}
		else{
			cout<<xx<<" "<<n-yy+1;
		}
	}
	return 0;
}




