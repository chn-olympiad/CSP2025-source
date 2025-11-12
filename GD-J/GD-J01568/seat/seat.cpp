#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,goal,cnt;
int a[105];

bool cmp(int x, int y){
	return x>y;
}

int main(){
	freopen("seat.in", "r", "stdin");
	freopen("seat.out", "w", "stdout");
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	goal = a[1];
	sort(a+1, a+1+n*m, cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i]==goal) goal = i;
	}
	for(int i=1; i<=m; i++){
		if(i%2==0){
			for(int j=n; j>=1; j--){
				cnt++;
				if(cnt==goal){
					cout << i << ' ' << j;
					return 0; 
				} 
			}
		}else{
			for(int j=1; j<=n; j++){
				cnt++;
				if(cnt==goal){
					cout << i << ' ' << j;
					return 0; 
				} 
			}
		}
	}
	return 0;
	
} 
