#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,score;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	score = a[1];
	int cnt = 0;
	sort(a+1,a+n*m+1,cmp);
	for(int c=1;c<=m;c++){
		if(c%2 == 1){
			for(int r=1;r<=n;r++){
				cnt ++ ;
				if(a[cnt] == score){
					cout << c << " " << r;
					return 0;
				}
			}
		}
		else{
			for(int r=n;r>=1;r--){
				cnt ++ ;
				if(a[cnt] == score){
					cout << c << " " << r;
					return 0;
				}
			}
		}
	}
	return 0;
} 
