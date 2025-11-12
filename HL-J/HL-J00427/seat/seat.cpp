#include<bits/stdc++.h>
using namespace std;
int n,m,a1;
int a[110];
int p;
int k;
bool flag = 1;//1 正序   0 倒序
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int p = n*m;
	for(int i = 1;i <= p;i++){
		cin >> a[i];
	}
	a1 = a[1];
	sort(a+1,a+p+1,cmp);
	for(int i = 1;i <= p;i++){
		if(a[i] == a1) k = i;
	}
	k--;
	int i = 1,j = 1;
	while(k--){
		if(flag == 1){
			if(i == n){
				j++;
				flag = 0;
			}else{
				i++;
			}
		}else{
			if(i == 1){
				j++;
				flag = 1;
			}else{
				i--;
			}
		}
	}
	cout << j << ' ' << i;
	return 0;
}