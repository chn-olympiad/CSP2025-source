#include<bits/stdc++.h>
using namespace std;
int n,m,a[201],posx=1,posy=1,fx=0,pos=1;//об0ср1ио2 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int lita=a[1];
	sort(a+1,a+n*m,cmp);
	int litanum;
	for(int i=1;i<=n*m;i++){
		if(a[i]==lita){
			litanum=i;
			break;
		}
	}
	int x=(litanum-1)/n+1;
	posx=x;
	if(x%2==1) posy=(litanum-1)%m+1;
	else posy=x*n-litanum+1;
	cout<<posx<<" "<<posy;
	return 0;
}
