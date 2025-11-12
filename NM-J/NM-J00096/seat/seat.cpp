#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=0;
		}
	}
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin >> b[i];
	}
	int zz=b[0];
	sort(b,b+n*m,cmp);
	queue<int> q;
	for(int i=0;i<n*m;i++){
		q.push(b[i]);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2!=0){
				a[n-1-j][i]=q.front();
				q.pop();
			}else{
				a[j][i]=q.front();
				q.pop();
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==zz){
				cout << i+1 << " " << j+1;
				return 0;
			}
		}
	}
	return 0;
}
