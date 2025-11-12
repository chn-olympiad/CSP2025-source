#include<bits/stdc++.h>
using namespace std;
int n,z[5005],cnt,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		maxx=max(maxx,z[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(z+1,z+n+1);
	if(n==3){
		if(z[1]+z[2]+z[3]>max(z[1],max(z[2],z[3]))*2)cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==4){
		if(z[1]+z[2]+z[3]>max(z[1],max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[4]>max(z[1],max(z[2],z[4]))*2)cnt++;
		
		if(z[1]+z[3]+z[4]>max(z[1],max(z[4],z[3]))*2)cnt++;
		
		if(z[2]+z[3]+z[4]>max(z[4],max(z[2],z[3]))*2)cnt++;
		
		if(z[1]+z[2]+z[3]+z[4]>max(max(z[1],z[4]),max(z[2],z[3]))*2)cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==5){
		if(z[1]+z[2]+z[3]>max(z[1],max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[4]>max(z[1],max(z[2],z[4]))*2)cnt++;
		if(z[1]+z[2]+z[5]>max(z[1],max(z[2],z[5]))*2)cnt++;
		
		if(z[1]+z[3]+z[4]>max(z[1],max(z[4],z[3]))*2)cnt++;
		if(z[1]+z[3]+z[5]>max(z[1],max(z[5],z[3]))*2)cnt++;
		
		if(z[1]+z[4]+z[5]>max(z[1],max(z[4],z[5]))*2)cnt++;
		
		if(z[2]+z[3]+z[4]>max(z[4],max(z[2],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[5]>max(z[5],max(z[2],z[3]))*2)cnt++;
		
		if(z[2]+z[4]+z[5]>max(z[4],max(z[2],z[5]))*2)cnt++;
		
		if(z[3]+z[4]+z[5]>max(z[5],max(z[4],z[3]))*2)cnt++;
		
		if(z[1]+z[2]+z[3]+z[4]>max(max(z[1],z[4]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[5]>max(max(z[1],z[5]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[4]+z[5]>max(max(z[1],z[4]),max(z[2],z[5]))*2)cnt++;
		if(z[1]+z[3]+z[4]+z[5]>max(max(z[1],z[4]),max(z[4],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[4]+z[5]>max(max(z[5],z[4]),max(z[2],z[3]))*2)cnt++;
		
		if(z[1]+z[2]+z[3]+z[4]+z[5]>max(z[5],max(max(z[1],z[4]),max(z[2],z[3])))*2)cnt++;
		cout<<cnt;
		return 0;
	}
	if(n==6){
		if(z[1]+z[2]+z[3]>max(z[1],max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[4]>max(z[1],max(z[2],z[4]))*2)cnt++;
		if(z[1]+z[2]+z[5]>max(z[1],max(z[2],z[5]))*2)cnt++;
		if(z[1]+z[2]+z[6]>max(z[1],max(z[2],z[6]))*2)cnt++;
		
		if(z[1]+z[3]+z[4]>max(z[1],max(z[4],z[3]))*2)cnt++;
		if(z[1]+z[3]+z[5]>max(z[1],max(z[5],z[3]))*2)cnt++;
		if(z[1]+z[3]+z[6]>max(z[1],max(z[6],z[3]))*2)cnt++;
		
		if(z[1]+z[4]+z[5]>max(z[1],max(z[4],z[5]))*2)cnt++;
		if(z[1]+z[4]+z[6]>max(z[1],max(z[4],z[6]))*2)cnt++;
		
		if(z[1]+z[5]+z[6]>max(z[1],max(z[6],z[5]))*2)cnt++;
		
		if(z[2]+z[3]+z[4]>max(z[4],max(z[2],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[5]>max(z[5],max(z[2],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[6]>max(z[6],max(z[2],z[3]))*2)cnt++;
		
		if(z[2]+z[4]+z[5]>max(z[4],max(z[2],z[5]))*2)cnt++;
		if(z[2]+z[4]+z[6]>max(z[4],max(z[2],z[6]))*2)cnt++;
		
		if(z[2]+z[5]+z[6]>max(z[6],max(z[2],z[5]))*2)cnt++;
		
		if(z[3]+z[4]+z[5]>max(z[5],max(z[4],z[3]))*2)cnt++;
		if(z[3]+z[4]+z[6]>max(z[6],max(z[4],z[3]))*2)cnt++;
		if(z[3]+z[5]+z[6]>max(z[5],max(z[6],z[3]))*2)cnt++;
		if(z[4]+z[5]+z[6]>max(z[5],max(z[4],z[6]))*2)cnt++;
		
		if(z[1]+z[2]+z[3]+z[4]>max(max(z[1],z[4]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[5]>max(max(z[1],z[5]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[6]>max(max(z[1],z[6]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[4]+z[5]>max(max(z[1],z[4]),max(z[2],z[5]))*2)cnt++;
		if(z[1]+z[2]+z[4]+z[6]>max(max(z[1],z[4]),max(z[2],z[6]))*2)cnt++;
		if(z[1]+z[3]+z[4]+z[5]>max(max(z[1],z[4]),max(z[5],z[3]))*2)cnt++;
		if(z[1]+z[3]+z[4]+z[6]>max(max(z[1],z[4]),max(z[6],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[4]+z[5]>max(max(z[5],z[4]),max(z[2],z[3]))*2)cnt++;
		if(z[2]+z[3]+z[4]+z[6]>max(max(z[6],z[4]),max(z[2],z[3]))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[4]+z[5]>max(z[5],max(max(z[1],z[4]),max(z[2],z[3])))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[4]+z[6]>max(z[6],max(max(z[1],z[4]),max(z[2],z[3])))*2)cnt++;
		if(z[1]+z[2]+z[3]+z[5]+z[6]>max(z[6],max(max(z[1],z[5]),max(z[2],z[3])))*2)cnt++;
		if(z[1]+z[2]+z[4]+z[5]+z[6]>max(z[6],max(max(z[1],z[4]),max(z[5],z[2])))*2)cnt++;
		if(z[1]+z[3]+z[4]+z[5]+z[6]>max(z[6],max(max(z[1],z[4]),max(z[5],z[3])))*2)cnt++;
		if(z[2]+z[3]+z[4]+z[5]+z[6]>max(z[6],max(max(z[5],z[4]),max(z[2],z[3])))*2)cnt++;
		
		if(z[1]+z[2]+z[3]+z[4]+z[5]+z[6]>maxx*2)cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}

