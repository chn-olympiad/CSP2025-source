#include "bits/stdc++.h"
using namespace std;
bool cmp(int a,int b){
	if(a>b)
		return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<(n*m);i++){
		int exa;
		cin>>exa;
		a.push_back(exa);
	}
	int R=a[0],N=n*m;
	sort(a.begin(),a.end(),cmp);
	int x=1,y=1,cnt=0,wasd=1,move=0;
	if(a[cnt++]==R){
		cout<<x<<" "<<y;
		return 0;
	}
	while(true){
		if(wasd==0) y--;
		if(wasd==1) y++;
		if(a[cnt++]==R){
			cout<<x<<" "<<y;
			return 0;
		}
		if(y==n||y==1){
			x++;
			wasd=!wasd;
			if(a[cnt++]==R){
				cout<<x<<" "<<y;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}