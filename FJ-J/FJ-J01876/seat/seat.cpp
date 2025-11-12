#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,m;
int a[110];
int b[15][15];
int x=1,y=1;
int t=1,p;
int k;
int d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	if(n==1){
		for(int i=1;i<=m;i++){
			if(a[i]==p){
				cout<<i<<' '<<1;
				break;
			}
		}
		return 0;
	}
	b[1][1]=a[1];
	if(m&1) k=n;
	else k=1;
	while(!(x==k&&y==m)){
//		cout<<y<<' '<<x<<endl;
		if(t!=1&&(x==1||x==n)){
			y++;
			b[x][y]=a[++t];
//			cout<<"b\n";
			if(n!=1){
				if(y&1){
					x++; 
				} 
				else x--;
				b[x][y]=a[++t];
//				cout<<"b\n";
				continue;
			}
		}
		
		else{
			if(y&1){
				x++; 
			} 
			else x--;
		}
		b[x][y]=a[++t];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<' ';
			if(b[i][j]==p){
				cout<<j<<' '<<i;
				break;
			}
		}
//		cout<<endl;
	}
	return 0;
} 
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
