#include<iostream>
#include<random>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN = 105;
int n,m,a[MAXN];
int graph[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int curr = 0,currx = 0,curry = 0;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	curr = a[1];
	sort(a+1,a+(n*m)+1);
	int k = n*m;
	int le = 1,ri = k;
	while(le<=ri){
		int temp = a[le];
		a[le] = a[ri];
		a[ri] = temp;
		le++;
		ri--;
	}
	int curriii = 1;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			graph[i][j] = a[curriii];
			if(graph[i][j]==curr){
				currx = i;
				curry = j;
			}
			curriii++;
		}
	}
	if(currx%2==1){
		cout << currx << " " << curry; 
	}
	else if(curr%2==0){
		int l = 1,r = n;
		while(l<=r){
			int temp = graph[currx][l];
			graph[currx][l] = graph[currx][r];
			graph[currx][r] = temp;
			l++;
			r--;
		}
		for(int i = 1;i<=n;i++){
			if(graph[currx][i]==curr){
				curry = i;
			}
		}
		cout << currx << " " << curry;
	}
	return 0;
} 
