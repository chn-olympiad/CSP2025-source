#include<bits/stdc++.h>
using namespace std;
const int N=500;
int t,n,a[N][3],maxx,num,b[20005];
void dfs(int i,int sum,int x,int y,int z){
	if(x>n) maxx=max(maxx,sum);
	else{
		if(x<n/2) dfs(i+1,sum+a[x][0],x+1,y,z);
		if(y<n/2) dfs(i+1,sum+a[x][1],x,y+1,z);
		if(z<n/2) dfs(i+1,sum+a[x][2],x,y,z+1);
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[a[i][0]]++;
			if(a[i][1]==0&&a[i][2]==0) num++;
			else if(a[i][2]==0&&a[i][1]!=0) num+=2;
		}if(num==n){
			int cnt=n/2,sum=0;
			for(int j=20000;j>=1;j--){
				if(b[j]>0){
					if(cnt>=b[j]) {sum+=b[j]*j;cnt-=b[j];}
					else if(cnt>0&&cnt<b[j]) {sum+=b[j]*cnt;break;}
					if(cnt<=0) break;
				}
			}cout<<sum;
			return 0;
		}else dfs(1,0,0,0,0);
		cout<<maxx;
	}
} 
