#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int n;
void zzx(){
	int sum=0;
	if(n==4){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) sum++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2) sum++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[4]),a[3])*2) sum++;
		if(a[2]+a[3]+a[4]>max(max(a[4],a[2]),a[3])*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],a[2]),max(a[3],a[4]))*2) sum++;
		cout<<sum;
	}
	else if(n==5){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) sum++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2) sum++;
		if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2) sum++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[3]),a[4])*2) sum++;
		if(a[1]+a[3]+a[5]>max(max(a[1],a[3]),a[5])*2) sum++;
		if(a[1]+a[4]+a[5]>max(max(a[1],a[4]),a[5])*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],max(a[2],a[3])),a[4])) sum++;
		if(a[1]+a[2]+a[3]+a[5]>max(max(a[1],max(a[2],a[3])),a[5])) sum++;
		if(a[1]+a[2]+a[4]+a[5]>max(max(a[1],max(a[2],a[4])),a[5]))sum++;
		if(a[1]+a[3]+a[4]+a[5]>max(max(a[1],max(a[3],a[4])),a[5])) sum++;
		if(a[2]+a[3]+a[4]+a[5]>max(max(a[2],max(a[3],a[4])),a[5])) sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>max(max(a[1],a[2]),max(a[3],max(a[4],a[5])))*2) sum++;
		cout<<sum;
	}
	else if(n==6){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2) sum++;
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2) sum++;
		if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2) sum++;
		if(a[1]+a[2]+a[6]>max(max(a[1],a[2]),a[6])*2) sum++;
		if(a[1]+a[3]+a[4]>max(max(a[1],a[3]),a[4])*2) sum++;
		if(a[1]+a[3]+a[5]>max(max(a[1],a[3]),a[5])*2) sum++;
		if(a[1]+a[3]+a[6]>max(max(a[1],a[3]),a[6])*2) sum++;
		if(a[1]+a[4]+a[5]>max(max(a[1],a[4]),a[5])*2) sum++;
		if(a[1]+a[4]+a[6]>max(max(a[1],a[4]),a[6])*2) sum++;
		if(a[1]+a[6]+a[5]>max(max(a[1],a[6]),a[5])*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]>max(max(a[1],max(a[2],a[3])),a[4])) sum++;
		if(a[1]+a[2]+a[3]+a[5]>max(max(a[1],max(a[2],a[3])),a[5])) sum++;
		if(a[1]+a[2]+a[3]+a[6]>max(max(a[1],max(a[2],a[3])),a[6])) sum++;
		if(a[1]+a[2]+a[4]+a[5]>max(max(a[1],max(a[2],a[4])),a[5])) sum++;
		if(a[1]+a[2]+a[4]+a[6]>max(max(a[1],max(a[2],a[4])),a[6])) sum++;
		if(a[1]+a[3]+a[4]+a[6]>max(max(a[1],max(a[3],a[4])),a[6])) sum++;
		if(a[1]+a[3]+a[4]+a[5]>max(max(a[1],max(a[3],a[4])),a[5])) sum++;
		if(a[1]+a[6]+a[4]+a[5]>max(max(a[1],max(a[6],a[4])),a[5])) sum++;
		if(a[2]+a[3]+a[4]+a[5]>max(max(a[2],max(a[3],a[4])),a[5])) sum++;
		if(a[2]+a[3]+a[4]+a[6]>max(max(a[2],max(a[3],a[4])),a[6])) sum++;
		if(a[2]+a[5]+a[4]+a[6]>max(max(a[2],max(a[5],a[4])),a[6])) sum++;
		if(a[2]+a[3]+a[5]+a[6]>max(max(a[2],max(a[3],a[5])),a[6])) sum++;
		if(a[5]+a[3]+a[4]+a[6]>max(max(a[5],max(a[3],a[4])),a[6])) sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>max(max(a[1],a[2]),max(a[3],max(a[4],a[5])))*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>max(max(a[1],a[2]),max(a[3],max(a[4],a[6])))*2) sum++;
		if(a[1]+a[2]+a[3]+a[6]+a[5]>max(max(a[1],a[2]),max(a[3],max(a[6],a[5])))*2) sum++;
		if(a[1]+a[2]+a[6]+a[4]+a[5]>max(max(a[1],a[2]),max(a[6],max(a[4],a[5])))*2) sum++;
		if(a[1]+a[6]+a[3]+a[4]+a[5]>max(max(a[1],a[6]),max(a[3],max(a[4],a[5])))*2) sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max(max(a[1],max(a[2],a[6])),max(a[3],max(a[4],a[5])))*2) sum++;
		cout<<sum;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int z=a[1]+a[2]+a[3];
	if(n==3&&z>max(max(a[1],a[2]),a[3])*2){
		cout<<1;
	}else if(n==3&&z<max(max(a[1],a[2]),a[3])*2){
		cout<<0;
	}
	if(n<=10&&n>=3){
		zzx();
	}
	return 0;
} 
