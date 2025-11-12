#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		a[1]=0;
		a[2]=0;
		a[3]=0;
		int n;
		cin>>n;
		int sx=INT_MIN;
		int sum=0;
		for(int i=1;i<=n;i++){
			int mx=INT_MIN;
			int c;
			int x,y,z;
			cin>>x>>y>>z;
			if(x>y) {
				mx=x;
				c=1;
			}
			else{
				mx=y;
				c=2;
			}
			if(mx<z){
				mx=z;
				c=3;
			}
			if(c==1) a[1]++;
			else if(c==2) a[2]++;
			else if(c==3) a[3]++;
			sum+=mx;
		}
		if(a[1]>a[2])sx=a[1];
		else sx=a[2];
		if(sx<a[3])sx=a[3];  
		if(sx>n/2) break;  
		cout<<sum<<endl;
	}
	return 0;
}
