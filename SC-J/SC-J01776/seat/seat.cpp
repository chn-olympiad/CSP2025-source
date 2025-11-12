#include<bits/stdc++.h>
using namespace std;

const int N=120;
int node[N][N];
int n,m,a1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	vector<int> a;
	a.push_back(114514);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			if(i*j==1)a1=x;
			a.push_back(x);
		}
	}
	sort(a.begin(),a.end(),[&](int a,int b)->bool{
		return a>b;
	});
	int tot=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==1)
				node[i][j]=a[++tot];
			else
				node[n-i+1][j]=a[++tot];
		} 
	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<node[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(node[i][j]==a1){
				cout<<j<<' '<<i<<'\n';
				return 0; 
			}
		}
	}
	return 0;
} 