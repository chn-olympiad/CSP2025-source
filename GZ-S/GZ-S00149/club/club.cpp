//贵阳市新世界学校 GZ-S00149 张哲睿 
#include<bits/stdc++.h>
using namespace std;
long long a[10000000][3],n,t,c[3],s,ss=0,d[10000000][3];
int sb(int x,int y,int z){
	if(x==n){
		if(y>s) s=y;
		if(z>=x){
			ss=1;
		}
		return 0;
	} 
	for(int i=0;i<3;i++){
		if(ss) break;
		if(c[i]<n/2) {
			c[i]++;
			int t=0;
			if(a[x][i]==max(a[x][0],max(a[x][1],a[x][2]))){
				z++;
				t=1;
			}
			sb(x+1,y+a[x][i],z);
			c[i]--;
			if(t) z--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int e=0;e<t;e++){
		
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		sb(0,0,0);
		cout<<s<<endl;
		s=0;
		ss=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
