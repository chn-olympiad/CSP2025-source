#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],temp,ansx=1,ansy=1,x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	temp=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(++x&&a[x]!=temp);
	for(int i=1;i<x;i++){
		if(ansx%2){
			if(ansy==n)ansx++;
			else ansy++;
		}
		else{
			if(ansy==1)ansx++;
			else ansy--;
		}
		//cout<<ansx<<' '<<ansy<<'\n';
	}
	cout<<ansx<<' '<<ansy;
	return 0;
} 
