#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int x;
	int y;
	int z;
	int m;
};
node a[500005];
int b[20];
int ans=0;
int e=0,f=0,g=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		e=0;
		f=0;
		g=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].m=max(max(a[i].x,a[i].y),a[i].z);
		}
		for(int j=1;j<=n;j++){
			if(a[i].m==a[i].x)e++;
			if(a[i].m==a[i].y)f++;
			if(a[i].m==a[i].z)g++;
			ans=a[i].m+ans;
		}
		if(e<=n/2 && f<=n/2 && g<=n/2){
			b[i]=ans;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<b[i]<<endl;
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
