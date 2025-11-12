#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int n,m;
int f[101];
int score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>score;
	f[score]++;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		f[x]++;
	}
	int index=n*m;
	for(int i=0;i<=100;i++){
		if(f[i]){
			if(i==score){
				break;
			}
			index-=f[i];
		}
	}
	int sx=index/n+1;
	int sy=index%n;
	if(sy==0){
		sx--;
		sy=n;
	}
	if(sx%2==0){
		sy=n-sy+1;
	}
	cout<<sx<<" "<<sy;
	return 0;
}
