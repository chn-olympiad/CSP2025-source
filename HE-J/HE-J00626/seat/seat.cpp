#include<bits/stdc++.h>
using namespace std;
const int N=150;
int n,m;
long long a[N][N];
long long  s[N];
bool cmp(int x,int y){
	return x>y;
}
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>s[i];
	}
	int xyh;
	xyh=s[1];
	sort(s+1,s+1+sum,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=s[cnt++];
		}
		i++;
		for(int j=n;j>=1;j--){
			a[i][j]=s[cnt++];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]==xyh){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
