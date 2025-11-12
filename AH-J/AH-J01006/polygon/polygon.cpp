#include<bits/stdc++.h>
using namespace std;

long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*a[3]) cnt++;
		if(a[1]+a[2]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[2]+a[3]+a[4]>2*a[4]) cnt++;
		cout<<cnt;
	}
	if(n==5){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*a[3]) cnt++;
		if(a[1]+a[2]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[2]+a[5]>2*a[5]) cnt++;
		
		if(a[1]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[4]+a[5]>2*a[5]) cnt++;
		if(a[2]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[2]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[2]+a[4]+a[5]>2*a[4]) cnt++;
		if(a[3]+a[4]+a[5]>2*a[5]) cnt++;
		cout<<cnt;
	}
	if(n==6){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*a[3]) cnt++;
		if(a[1]+a[2]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[2]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[2]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[3]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[4]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[5]+a[6]>2*a[6]) cnt++;
		if(a[2]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[2]+a[3]+a[6]>2*a[6]) cnt++;
		if(a[2]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[2]+a[4]+a[5]>2*a[4]) cnt++;
		if(a[2]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[3]+a[4]+a[5]>2*a[5]) cnt++;
		if(a[3]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[3]+a[5]+a[6]>2*a[6]) cnt++;
	}
	if(n==7){
		int cnt=0;
		if(a[1]+a[2]+a[3]>2*a[3]) cnt++;
		if(a[1]+a[2]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[2]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[2]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[2]+a[7]>2*a[7]) cnt++;
		if(a[1]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[1]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[3]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[3]+a[7]>2*a[7]) cnt++;
		if(a[1]+a[4]+a[5]>2*a[5]) cnt++;
		if(a[1]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[4]+a[7]>2*a[7]) cnt++;
		if(a[1]+a[5]+a[6]>2*a[6]) cnt++;
		if(a[1]+a[5]+a[7]>2*a[7]) cnt++;
		if(a[1]+a[6]+a[7]>2*a[7]) cnt++;
		if(a[2]+a[3]+a[4]>2*a[4]) cnt++;
		if(a[2]+a[3]+a[6]>2*a[6]) cnt++;
		if(a[2]+a[3]+a[5]>2*a[5]) cnt++;
		if(a[2]+a[3]+a[7]>2*a[7]) cnt++;
		
		if(a[2]+a[4]+a[5]>2*a[4]) cnt++;
		if(a[2]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[2]+a[4]+a[7]>2*a[7]) cnt++;
		if(a[2]+a[5]+a[6]>2*a[6]) cnt++;
		if(a[2]+a[5]+a[7]>2*a[7]) cnt++;
		if(a[2]+a[6]+a[7]>2*a[7]) cnt++;
		if(a[3]+a[4]+a[5]>2*a[5]) cnt++;
		if(a[3]+a[4]+a[6]>2*a[6]) cnt++;
		if(a[3]+a[4]+a[7]>2*a[7]) cnt++;
		if(a[3]+a[5]+a[7]>2*a[7]) cnt++;
		if(a[3]+a[5]+a[6]>2*a[6]) cnt++;
		if(a[3]+a[6]+a[7]>2*a[7]) cnt++;
		if(a[4]+a[5]+a[6]>2*a[6]) cnt++;
		if(a[4]+a[5]+a[7]>2*a[7]) cnt++;
		if(a[4]+a[6]+a[7]>2*a[7]) cnt++;
		if(a[5]+a[6]+a[7]>2*a[7]) cnt++;
		cout<<cnt;
	}
	return 0;
}
