#include<bits/stdc++.h>
using namespace std;
int a[5005];
int cnt,c,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int m;
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>a[i];
		c+=a[i];
	}	
	cin>>c;
	for(int i=3;i<=m;i++){
		sum=a[i]+a[i-1];
		if(c>2*max(sum,1)){
			cnt++;
		}
	}
	if(cnt<244){
		cout<<cnt;
	}
	else if(cnt>244&&cnt<353){
		cout<<cnt%244;
	}
	else if(cnt>353&&cnt<998){
		cout<<cnt%353;
	}
	else{
		cout<<cnt%998;
	}
	return 0;
}
