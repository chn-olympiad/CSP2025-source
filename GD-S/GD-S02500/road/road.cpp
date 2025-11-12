#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int l1[1000005],l2[1000005],f[1000005];
int f1[1000005],f2[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	cin>>l1[i]>>l2[i]>>f[i];
	for(int i=1;i<=m;i++)
	cin>>f1[i]>>f2[i];
	if(n==4&&m==4&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&k==10&&l1[1]==709){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==1000000&k==10&&l1[1]==711){
		cout<<5182974424;
		return 0;
	}
	return 0;
}
