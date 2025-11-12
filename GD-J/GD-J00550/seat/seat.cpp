#include <bits/stdc++.h>
using namespace std; 
const int N=105;
int c[N]; 
int d[N][N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number","r",stdin);
    freopen("number","w",stdout);
	int a,b;
	cin >> a >> b;
	int n=a*b;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	int zhao=c[1];
	int cnt=1;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cnt++;
			if(c[cnt]==zhao){
				cout << i << " " << j;
			}
		}
	}
} 
