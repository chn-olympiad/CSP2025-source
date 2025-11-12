#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int ans=0;
int a[N][8];
int p[N];
int cnt=0;
int x,y,z;
void init(){
	memset(a,0,sizeof(0));
	memset(p,0,sizeof(p));
	cnt=0;
	ans=0;
	x=0,y=0,z=0;
	return ;
}
bool cmp(int x,int y){
	return a[x][6]<a[y][6];
}
void work(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		a[i][4]=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=a[i][4];
		if(a[i][4]==a[i][1]){
			x++;
			a[i][6]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		}
		else if(a[i][4]==a[i][2]){
			y++;
			a[i][6]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		}
		else{
			z++;
			a[i][6]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
		}
	}
	int mm=n/2;
	if(x>mm){
		for(int i=1;i<=n;i++){
			if(a[i][4]==a[i][1]){
				cnt++;
				p[cnt]=i;
			}
		}
	}
	else if(y>mm){
		for(int i=1;i<=n;i++){
			if(a[i][4]==a[i][2]){
				cnt++;
				p[cnt]=i;
			}
		}
	} 
	else if(z>mm){
		for(int i=1;i<=n;i++){
			if(a[i][4]==a[i][3]){
				cnt++;
				p[cnt]=i;
			}
		}
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt-mm;i++){
		ans-=a[p[i]][6];
	} 
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		init();
		work();
	}
	return 0;
}
