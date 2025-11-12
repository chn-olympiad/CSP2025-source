//GZ-S00248 毕节市第一中学 李鹏程 
#include<bits/stdc++.h>
using namespace std;
int Max(int a,int b,int c){
	return max(max(a,b),c);
}
int a[3][100001]={};
int bfs(int x,int y,int a1,int b,int c,int pd,int ans,int key){
	if(y==key) return ans+a[x][y];
	if(a1<pd&&b<pd&&c<pd) return Max(bfs(0,y+1,a1+1,b,c,pd,ans+a[x][y],key),bfs(1,y+1,a1,b+1,c,pd,ans+a[x][y],key),bfs(2,y+1,a1,b,c+1,pd,ans+a[x][y],key)); 
	if(c>=pd) return max(bfs(0,y+1,a1+1,b,c,pd,ans+a[x][y],key),bfs(1,y+1,a1,b+1,c,pd,ans+a[x][y],key));
	if(b>=pd) return max(bfs(0,y+1,a1+1,b,c,pd,ans+a[x][y],key),bfs(2,y+1,a1,b,c+1,pd,ans+a[x][y],key)); 
	if(a1>=pd) return max(bfs(1,y+1,a1,b,c+1,pd,ans+a[x][y],key),bfs(2,y+1,a1,b+1,c,pd,ans+a[x][y],key)); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int b[t];
	long long ans[t]={};
	int k=0;
	while(k<t){
		cin>>b[k];
		int end=b[k]/2,right=b[k]-1;
		for(int i=0;i<b[k];i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
		}
		ans[k]=Max(bfs(0,0,1,0,0,end,0,right),bfs(1,0,0,1,0,end,0,right),bfs(2,0,0,0,1,end,0,right));
		k++;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

