#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct jgt{
	int x,y,pm;
}a[11][11];
int n,m,a1,a2;
int p;
vector<int> s;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	s.push_back(a1);
	for(int i=0;i<n*m-1;i++){
		cin>>a2;
		s.push_back(a2);
	}
	sort(s.begin(),s.end(),px);
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			if(i==1){	
				a[i][j].pm=j;
						
			}
			else if(i==2 && j==1){
				a[i][j].pm=a[i-1][j+1].pm*n;
			}
			else a[i][i].pm=a[i-2][j].pm+n*2;
			a[i][j].x=i;
			a[i][j].y=j;
			}
		}
	for(int i=0;i<n*m;i++){
		if(s[i]==a1){
			p=i+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j].pm==p){
				cout<<a[i][j].x<<' '<<a[i][j].y;
			}
		}
	}
	return 0;
}
