#include<bits/stdc++.h>
using namespace std;
int n,TnotFFT,ans,d;
int a[100005][5];
int v[5][100005];
int h[5],t[5];
void show(){
	for(int i=1;i<=3;i++){
			for(int j=h[i]+1;j<=t[i];j++){
				cout<<v[i][j]<<' ';
			}
			cout<<'\n';
	}
}
bool cmp(int x,int y){
	if(d==1) return (a[x][1]-max(a[x][2],a[x][3]))<(a[y][1]-max(a[y][2],a[y][3]));
	if(d==2) return (a[x][2]-max(a[x][1],a[x][3]))<(a[x][2]-max(a[x][1],a[x][3]));
	return (a[x][3]-max(a[x][2],a[x][1]))<(a[x][3]-max(a[x][2],a[x][1]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>TnotFFT;
	while(TnotFFT--){
		cin>>n,ans=0,h[1]=h[2]=h[3]=0,t[1]=t[2]=t[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) v[1][++t[1]]=i;
			if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]) v[2][++t[2]]=i;
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]) v[3][++t[3]]=i;
		}
		if(t[1]>n/2||t[2]>n/2||t[3]>n/2){
			if(t[1]>n/2) d=1;
			else if(t[2]>n/2) d=2;
			else d=3;
			//show();
			sort(v[d]+1,v[d]+t[d]+1,cmp);
			//show();
			for(int i=1;i<=t[d]-n/2;i++){
				if(d==1)
					if(a[v[1][i]][2]<a[v[1][i]][3])
						v[3][++t[3]]=v[1][i],h[1]++;
					else
						v[2][++t[2]]=v[1][i],h[1]++;					
				else
					if(d==2)
						if(a[v[2][i]][1]<a[v[2][i]][3])
							v[3][++t[3]]=v[2][i],h[2]++;
						else
							v[1][++t[1]]=v[2][i],h[2]++;
					else
						if(a[v[3][i]][2]<a[v[3][i]][1])
							v[1][++t[1]]=v[3][i],h[3]++;
						else
							v[2][++t[2]]=v[3][i],h[3]++;
				//show();
			}
				
		}
		for(int i=1;i<=3;i++){
			for(int j=h[i]+1;j<=t[i];j++){
				ans+=a[v[i][j]][i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
