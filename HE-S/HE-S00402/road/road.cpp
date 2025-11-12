#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
long long n,m,k,u,v,w,c[11]={},a[11][10001]={},book[10001][10001]={};
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		book[u][v]=w;
		book[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin.close();
	cout.close(); 
	return 0;
}
