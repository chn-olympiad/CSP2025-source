#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
int v[MAXN],val,n,m;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>v[1]; val=v[1];
	for(int i=2;i<=n*m;i++) cin>>v[i];
	sort(v+1,v+1+n*m,cmp);
	int drop=1,x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(v[i]==val){
			cout<<y<<' '<<x;
			return 0;
		}
		if((drop?x+1<=n:x-1>=1)) x+=(drop?1:-1);
		else{
			y++;
			drop^=1;
		}
	}
	return 0;
}
