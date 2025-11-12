#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,m,cnt=1,dxx=1,dyy=1,x=1;
int a[20][20],b[110];
int dx[]={0,0,1,0,1};
int dy[]={0,1,0,-1,0};
bool cmp(int x,int y){
	return x>y;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>b[i];
	int c=b[1];
	sort(b+1,b+1+(n*m),cmp);//cout<<b[1]<<endl;
	while(cnt!=n*m+1){
		a[dxx][dyy]=b[cnt];//cout<<cnt<<" "<<b[cnt]<<" ";
		if(a[dxx][dyy]==c){cout<<dxx<<" "<<dyy;return 0;}
		if(dyy+dy[x]>n||dyy+dy[x]==0||x==2||x==4){
			if(x==4) x=1;
			else x++;
		}
		dxx+=dx[x];dyy+=dy[x];
		cnt++;
	}
	cout<<"Error???";

	
	return 0;
}
