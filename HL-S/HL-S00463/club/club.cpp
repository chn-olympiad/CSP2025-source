#include<bits/stdc++.h>
using namespace std;
int t,ans,a[10]={};
int b[100005][3]={};
int n,x,y,z,count=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int d=t;
	while(t){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			ans+=max(max(x,y),z);
		}
		a[d-t]=ans;
		t--;
		ans=0; 
	}
	for(int i=0;i<d;i++){
		cout<<a[i];
		if(i+1<d){
			cout<<endl;
		}
	}
	
	return 0;
}
