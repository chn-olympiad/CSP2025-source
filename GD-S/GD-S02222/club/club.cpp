#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t,ans=0;
int x,y,z,o1=0,o2=0,o3=0;
int q[10];
int solve(){
	int num=0,n;
	q[1]=0,q[2]=0,q[3]=0;
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>x>>y>>z;
		if(x>y && x>z){
			q[j]=x;
			o1++;
		}
	    if(y>x && y>z){
			q[j]=y;
			o2++;
		}
		if(z>x && z>y){
			q[j]=z;
			o3++;
		}
	}
	o3-=4;
	if(o1<=n/2 && o2<=n/2 && o3<=n/2){
		ans=q[1]+q[2]+q[3]+q[4];
		return ans;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<solve()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
