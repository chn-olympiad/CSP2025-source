#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cn=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			cn=a[i];
		}
	}
	sort(a+1,a+1+n*m,greater<int>());
	int xtx=0,ytx=0,cnt=0;
	for(int i=1;i<=n*m;i++){
		cnt++;
		if(a[i]==cn){
			break;
		}
	}
	int hh=cnt%m;
	int ee=int(ceil(cnt*1.0/n));
	if(hh==0) hh=m;
	cout<<ee<<' ';
	if(ee%2==0){
		cout<<m-hh+1;
	}else{
		cout<<hh;
	}
	return 0;
} 
