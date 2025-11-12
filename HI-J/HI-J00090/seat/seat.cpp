#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],tmp,cnt,timest;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	tmp = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == tmp){
			cnt = i;
			break;
		}
	}
	for(int i = 1;i <= m;i++){
		if(i % 2 != 0){
			for(int j = 1;j <= n;j++){
				timest++;
				if(timest == cnt){
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j = n;j >= 1;j--){
				timest++;
				if(timest == cnt){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
