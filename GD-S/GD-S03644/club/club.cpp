#include<bits/stdc++.h>
using namespace std;
long long a[100005][3],c[100005],o1,o2,o3;
void solve(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n;
	o1=0;
	o2=0;
	o3=0;
	cin>>n;
	long long ct=0;
	for(long long i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(max(max(a[i][1],a[i][2]),a[i][0])==a[i][0]){
			o1++;
			ct+=a[i][0];
		}
		else if(max(max(a[i][1],a[i][2]),a[i][0])==a[i][1]){
			ct+=a[i][1];
			o2++;
		}
		else{
			o3++;
			ct+=a[i][2];
		}
 		c[i]=a[i][0]+a[i][1]+a[i][2]-max(max(a[i][1],a[i][2]),a[i][0])-min(min(a[i][1],a[i][2]),a[i][0]);
 		c[i]=max(max(a[i][1],a[i][2]),a[i][0])-c[i];
	}
	if(max(o1,max(o2,o3))>n/2){
		long long v=max(o1,max(o2,o3))-n/2;
		sort(&c[0],&c[n]);
		for(long long i;i<v;i++){
			ct-=c[i];
		}
	}
	cout<<ct<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
}
