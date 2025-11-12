#include<bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0;
int w[10005][5];
int q[10005][2]={0};
int n,minn=1000005;
/*int f(){
	int x;
	for(int i=0;i<n;i++){
		if(q[i][1]==0){
			minn=min(minn,q[i][0]);
			x=i;
			q[i][0]=minn;
		}
	}
	for(int i=0;i<n;i++){
		if(q[i][1]==0){
			minn=min(minn,q[i][0]);
			x=i;
			q[i][0]=minn;
		}
	}
}
int g(){
		
}
int h(){
	
}*/
void solve(){	
	cin>>n;
	int num=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>w[i][j];
			if(q[i][0]<w[i][j]){
				q[i][0]=w[i][j];
				q[i][1]=j;
			}
		}
	}
	/*for(int i=0;i<n;i++){
		if(q[i][1]==0){
			a++;
		}
		if(q[i][1]==1){
			b++;
		}
		if(q[i][1]==2){
			c++;
		}
		
		if(a>n/2){
			f();
		}
		if(b>n/2){
			g();
		}
		if(c>n/2){
			h();
		}
	}*/
	for(int i=0;i<n;i++){
		num+=q[i][0];
	}
	cout<<num<<endl;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
