#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,z;
}a[100100];
int n,X,Y,Z,ans;
void func(int b,int c){
	if(b>n){
		if(c>=ans)ans=c;
		return;
	}
	if(X<n/2){
		X++;
		func(b+1,c+a[b].x);
		X--;
	}
	if(Y<n/2){
		Y++;
		func(b+1,c+a[b].y);
		Y--;
	}
	if(Z<n/2){
		Z++;
		func(b+1,c+a[b].z);
		Z--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		X=0,Y=0,Z=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		func(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
