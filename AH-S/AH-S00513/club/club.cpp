 #include<bits/stdc++.h>
using namespace std;
int n,t,a[100000],b[100000],c[100000],maxx,temp;
void dfs(int sum,int x,int y,int z,int v){
	temp++;
	if(v==n+2){
		return;
	}
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	maxx=max(maxx,sum);
	dfs(sum+a[v],x+1,y,z,v+1);
	dfs(sum+b[v],x,y+1,z,v+1);
	dfs(sum+c[v],x,y,z+1,v+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];	
		}
		dfs(0,0,0,0,1);
		cout<<maxx<<endl;
		maxx=0;
	}
	return 0;
}
