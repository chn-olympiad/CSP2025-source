#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m,y;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	y=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++){
		if(a[i]==y){
			y=i;
			break;
		}
	}
	int d=y/n,c=y%n;
	if(c!=0){
		d++;
	}else{
		c=n;
	}
	if(d%2==0){
		c=n+1-c;
	}
	cout<<d<<" "<<c;
	return 0;
} 
