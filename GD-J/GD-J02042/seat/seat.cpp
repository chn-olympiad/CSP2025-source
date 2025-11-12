#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],ai,d=1,ansx=1,ansy=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)ai=a[i];
	} 
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==ai){
			cout<<ansx<<' '<<ansy;
			return 0; 
		}
		if(ansy+d>n or ansy+d<1){
			d*=-1;
			ansx++;
		}
		else ansy+=d;
	} 
	return 0;
}
