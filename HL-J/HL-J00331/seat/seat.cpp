#include<bits/stdc++.h>
using namespace std;
int a[114][514];
int stu[10086];
bool cmp(int p , int q){
	return p > q;
}
//¿ÉÒÔ¡¢°Ù°É 
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> stu[i];
	}
	ans = stu[1];
	sort(stu + 1 , stu + 1 + n * m , cmp);
	int y = 1;
	int tot = 1;
	int flag = 0;
	while(1){
		if(!flag){
			for(int i = 1;i <= n;i ++){
				if(stu[tot] == ans){
					cout << y << ' ' << i;
					return 0; 
				}
				tot ++;
			}
			flag = 1;
			y ++;
			continue;
		}
		if(flag){
			for(int i = n;i >= 1;i --){
				if(stu[tot] == ans){
					cout << y << ' ' << i;
					return 0; 
				}
				tot ++;
			}
			flag = 0;
			y ++;
			continue;
		}
	}
	return 0;
}
