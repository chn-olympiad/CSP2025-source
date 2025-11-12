#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=max(a[1],max(a[2],a[3])),c=min(a[1],min(a[2],a[3]));
	if(a[1]!=b && a[1]!=c) if(a[1]+c>b*2) sum++;
	if(a[2]!=b && a[2]!=c) if(a[2]+c>b*2) sum++;
	if(a[3]!=b && a[3]!=c) if(a[3]+c>b*2) sum++;
	cout<<sum;
	return 0;
}
