#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
bool comp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0,now=0;
	cin>>n>>m;
	vector<int> maze(n*m+1);
	for(ll i=1;i<=n*m;i++){
		cin>>maze[i];
	}
	ans=maze[1];
	sort(maze.begin()+1,maze.end(),comp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==1) now=maze[(j-1)*n+1+i-1];
			else now=maze[j*n-i+1];
			if(now==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
//	cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

