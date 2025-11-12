#include<bits/stdc++.h>
using namespace std;
const long long a=122,x=11,y=11;
long long n, m, p,l=1,r=1;
bool v=0,u=1;
long long t[a];
long long b[x][y];
bool mc(long long a, long long b){
	if(a>b){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++){
		cin>> t[i] ;
		if(i==1){
			p=t[i];
		}
	}
	sort(t+1,t+n*m+1,mc);
	b[1][1]=t[1];
	for(int k=2; k<=n*m; k++){
		if(v==0){
			l++;
		}
		if(v==1){
			l--;
		}
		b[l][r]=t[k];
		if(l==m&&u==1){
			r+=1;
			l++;
			v=1;
			u=0;
		}else if(l==1&&u==1){
			r+=1;
			l--;
			v=0;
			u=0;
		}else{
			u=1;
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==p){
				cout << j << " "<< i ;
				return 0;
			}
		}
		cout << endl ;
	}
	return 0;
}
