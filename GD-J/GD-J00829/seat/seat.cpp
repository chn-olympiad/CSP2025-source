#include<bits/stdc++.h>
using namespace std;
int n,m,scr[105],sqr,r,inx;
bool comp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sqr=n*m;
	for(int i=1;i<=sqr;i++){
		cin>>scr[i];
	}
	r=scr[1];
	sort(scr+1,scr+1+sqr,comp);
	for(int i=1;i<=sqr;i++){
		if(scr[i]==r){
			inx=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				inx--;
				if(!inx){
					cout<<i<<' '<<j;
				return 0;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--){
				inx--;
				if(!inx){
					cout<<i<<' '<<j;
				return 0;
				}
			}
		}
	}
	return 0;
}
