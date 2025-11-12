#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin >>a[i];
	}
	int u = a[1];
	int sum = n*m;
	sort(a+1,a+1+sum,cmp);
	int cnt=0;
	for(int i = 1;i <= sum;i++){
		if(a[i] == u){
			u = i;
			break;
		}
	}
	for(int i = 1;i <= m;i++){
		if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				cnt++;
				if(cnt==u){
					cout <<i<<" "<<j;return 0;
				}
			}
		}
		else{
			for(int j = 1;j <= n;j++){
				cnt++;
				if(cnt == u){
					cout <<i<<" "<<j;return 0;
				}
			}
		}
	}	
	return 0;
}