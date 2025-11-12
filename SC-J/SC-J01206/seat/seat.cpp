#include<bits/stdc++.h>
using namespace std;
#define maxn 15
//不开long long见祖宗
struct coord{
	int x,y;
};
int n,m,rmao;
int a[maxn*maxn];
coord jl[maxn*maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
		cin>>a[i];
	rmao = a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==rmao){
		cout<<"1 1\n"<<'\n';
		return 0;
	}
	jl[1].x = 1;
	jl[1].y = 1;
	for(int i = 2;i<=n*m;i++){
		if(jl[i-1].y%2==0){
			if(jl[i-1].x==1){
				jl[i].x = 1;
				jl[i].y = jl[i-1].y+1;
			}
			else{
				jl[i].x = jl[i-1].x-1;
				jl[i].y = jl[i-1].y;
			}
		}
		else{
			if(jl[i-1].x==n){
				jl[i].x = n;
				jl[i].y = jl[i-1].y+1;
			}
			else{
				jl[i].x = jl[i-1].x+1;
				jl[i].y = jl[i-1].y;
			}
		}
		if(rmao==a[i]){
			cout<<jl[i].y<<' '<<jl[i].x<<'\n';
			break;
		}
	}
	return 0;
}
//我爱丽丝最可爱
