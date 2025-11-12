#include<bits/stdc++.h>
using namespace std;
int i,j,a[6000],n,c=0,x,y,b[6000],u,v;
/*void dfs(int s,int t){
//	if(x>t){
//		sort(a,a+t);
//		u=0;
//		for(i=0;i<t;i++){
//			u+=b[i];
//		}
//		if(u>b[t-1]*2) c++;
//		return ;
//	}
//	for(i=x;i<=n;i++){
//		b[i]=a[i+t];
//		dfs(i,t);
//	}
}*/
int main(){
	//freopen("polygon.in","r",stdin); 
	//freopen("polygon.out","w",stdout); 
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=3;i<n;i++){
		v=1;
		for(j=i;j<n;j++){
			v*=n-j;
		}
		c+=v;
	}
	c++;
	cout<<c%998%244%353<<endl;
	return 0;
}
