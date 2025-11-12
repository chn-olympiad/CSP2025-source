#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int sum,num,snum=-1e9,e;
int a[514514];
int pm[114],pk[514];
void Ciallo(int d){
	num=1;
	while(d>0){
		pm[num]+=d%2;
		d/=2;
		num++;
		if(d==0)break;
	}
	snum=max(snum,num);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out,"w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	sum=1,e=k;
	while(e>0){
		pk[sum]+=e%2;
		e/=2;
		sum++;
	}
	sum--;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]!=0&&a[i]!=k)Ciallo(a[i]);
		if(a[i]==k)ans++;
	}
	if(snum<k)cout<<ans;
	else {
		snum=1e9;
		for(int i=1;i<=sum;i++)snum=min(snum,pm[i]/pk[i]);
		ans+=snum;
		cout<<ans;
	}
	return 0;
}
//Ciallo~(<`w~)
