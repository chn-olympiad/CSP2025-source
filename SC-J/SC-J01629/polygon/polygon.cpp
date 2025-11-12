#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1<<endl;
		 cout<<0<<endl;
	} if(n==4){
		int cnt=0;
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cnt++;
		 if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) cnt++;
		 if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) cnt++;
		 if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],a[4]),max(a[2],a[3]))*2) cnt++;
		cout<<cnt<<endl;
	} if(n==5){
		int cnt=0;
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cnt++;
		 if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) cnt++;
		 if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2) cnt++;
		 if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) cnt++;
		 if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2) cnt++;
		 if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2) cnt++;
		 if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) cnt++;
		 if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2) cnt++;
		 if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2) cnt++;
		 if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2) cnt++;
		//
		 if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],a[2]),max(a[3],a[4]))*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[5]>max(max(a[1],a[2]),max(a[3],a[5]))*2) cnt++;
		 if(a[1]+a[2]+a[4]+a[5]>max(max(a[1],a[2]),max(a[4],a[5]))*2) cnt++;
		 if(a[1]+a[3]+a[4]+a[5]>max(max(a[1],a[3]),max(a[4],a[5]))*2) cnt++;
		 if(a[2]+a[3]+a[4]+a[5]>max(max(a[1],a[3]),max(a[4],a[5]))*2) cnt++;
		//
		 if(a[1]+a[2]+a[3]+a[4]+a[5]>max(max(max(a[1],a[2]),max(a[3],a[4])),a[5])*2) cnt++;
		cout<<cnt<<endl;
	} if(n==6){
		int cnt=0;
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cnt++;
		 if(a[1]+a[2]+a[4]>max(a[1],max(a[2],a[4]))*2) cnt++;
		 if(a[1]+a[2]+a[5]>max(a[1],max(a[2],a[5]))*2) cnt++;
		 if(a[1]+a[2]+a[6]>max(a[1],max(a[2],a[6]))*2) cnt++;
		 if(a[1]+a[3]+a[4]>max(a[1],max(a[3],a[4]))*2) cnt++;
		 if(a[1]+a[3]+a[5]>max(a[1],max(a[3],a[5]))*2) cnt++;
		 if(a[1]+a[3]+a[6]>max(a[1],max(a[3],a[6]))*2) cnt++;
		 if(a[1]+a[4]+a[5]>max(a[1],max(a[4],a[5]))*2) cnt++;
		 if(a[1]+a[4]+a[6]>max(a[1],max(a[4],a[6]))*2) cnt++;
		 if(a[1]+a[5]+a[6]>max(a[1],max(a[5],a[6]))*2) cnt++;
		 if(a[2]+a[3]+a[4]>max(a[2],max(a[3],a[4]))*2) cnt++;
		 if(a[2]+a[3]+a[5]>max(a[2],max(a[3],a[5]))*2) cnt++;
		 if(a[2]+a[3]+a[6]>max(a[2],max(a[3],a[6]))*2) cnt++;
		 if(a[2]+a[4]+a[5]>max(a[2],max(a[4],a[5]))*2) cnt++;
		 if(a[2]+a[4]+a[6]>max(a[2],max(a[4],a[6]))*2) cnt++;
		 if(a[2]+a[5]+a[6]>max(a[2],max(a[5],a[6]))*2) cnt++;
		 if(a[3]+a[4]+a[5]>max(a[3],max(a[4],a[5]))*2) cnt++;
		 if(a[3]+a[4]+a[6]>max(a[3],max(a[4],a[6]))*2) cnt++;
		 if(a[3]+a[5]+a[6]>max(a[3],max(a[5],a[6]))*2) cnt++;
		 if(a[4]+a[5]+a[6]>max(a[4],max(a[5],a[6]))*2) cnt++;
		//
		 if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],a[2]),max(a[3],a[4]))*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[5]>max(max(a[1],a[2]),max(a[3],a[5]))*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[6]>max(max(a[1],a[2]),max(a[3],a[6]))*2) cnt++;
		 if(a[1]+a[2]+a[4]+a[5]>max(max(a[1],a[2]),max(a[4],a[5]))*2) cnt++;
		 if(a[1]+a[2]+a[4]+a[6]>max(max(a[1],a[2]),max(a[4],a[6]))*2) cnt++;
		 if(a[1]+a[3]+a[4]+a[5]>max(max(a[1],a[3]),max(a[4],a[5]))*2) cnt++;
		 if(a[1]+a[3]+a[4]+a[6]>max(max(a[1],a[3]),max(a[4],a[6]))*2) cnt++;
		 if(a[1]+a[3]+a[5]+a[6]>max(max(a[1],a[3]),max(a[5],a[6]))*2) cnt++;
		 if(a[1]+a[4]+a[5]+a[6]>max(max(a[1],a[4]),max(a[5],a[6]))*2) cnt++;
		 if(a[2]+a[3]+a[4]+a[5]>max(max(a[2],a[3]),max(a[4],a[5]))*2) cnt++;
		 if(a[2]+a[3]+a[4]+a[6]>max(max(a[2],a[3]),max(a[4],a[6]))*2) cnt++;
		 if(a[2]+a[4]+a[5]+a[6]>max(max(a[2],a[4]),max(a[5],a[6]))*2) cnt++;
		 if(a[3]+a[4]+a[5]+a[6]>max(max(a[3],a[4]),max(a[5],a[6]))*2) cnt++;
		//
		 if(a[1]+a[2]+a[3]+a[4]+a[5]>max(max(max(a[1],a[2]),max(a[3],a[4])),a[5])*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[4]+a[6]>max(max(max(a[1],a[2]),max(a[3],a[4])),a[6])*2) cnt++;
		 if(a[1]+a[2]+a[3]+a[5]+a[6]>max(max(max(a[1],a[2]),max(a[3],a[5])),a[6])*2) cnt++;
		 if(a[1]+a[2]+a[4]+a[5]+a[6]>max(max(max(a[1],a[2]),max(a[4],a[5])),a[6])*2) cnt++;
		 if(a[1]+a[3]+a[4]+a[5]+a[6]>max(max(max(a[1],a[3]),max(a[4],a[5])),a[6])*2) cnt++;
		 if(a[2]+a[3]+a[4]+a[5]+a[6]>max(max(max(a[2],a[3]),max(a[4],a[5])),a[6])*2) cnt++;
		//
		 if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max(max(max(a[1],a[2]),max(a[3],a[4])),max(a[5],a[6])*2))cnt++;
		cout<<cnt<<endl;
	}
	return 0;
} 