#include<bits/stdc++.h>
using namespace std;
int mp[15][15],a[105],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int cj=a[1];
	sort(a+1,a+l+1,cmp);
	int mc;
	for(int i=1;i<=l;i++){
		if(a[i]==cj){
			mc=i;
			break;
		}
	}
	int x=1,y=0,zt=1;
	for(int i=1;i<=l;i++){
		if(zt){
			y++;
		}else{
			y--;
		}
		if(y>n){
			x++;
			y--;
			zt=0;
		}
		if(y<1){
			x++;
			y++;
			zt=1;
		}
		if(i==mc){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
