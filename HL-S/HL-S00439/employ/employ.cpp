#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[101],s=0,z=0,w=0;
	int t;
	cin>>n>>m;
	cin>>t;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int i=100*n;i>0;i-=10){
			t=t%i;
			if(z>=a[i])break;
			if(t/i==1) s+=1;break;
			z+=1;
	}}
	if(s>=m)w+=1;
	cout<<w%998%244%353;
	return 0;
}