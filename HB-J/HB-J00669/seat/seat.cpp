#include <bits/stdc++.h>
using namespace std;
int n,m,s[100],k;
int main(){
	cin >> n >> m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i = 0;i < n*m;i ++) cin >> s[i];
	int x = s[0];
	for(int i = 0;i < n*m-1;i ++) if(s[i] < s[i+1]) swap(s[i],s[i+1]);
	for(int i = 0;i < m;i ++){
		if(i%2 == 0){
			for(int j = 0;j < n;j ++){
				if(s[k] == x){
					cout << i+1 << " " << j+1;
					return 0;
				}
				k ++;
			}
		}else{   
			for(int j = n-1;j >= 0;j --){
				if(s[k] == x){
					cout << i+1 << " " << j+1;
					return 0;
				}
				k ++;
			}
		}
	}
	return 0;
}
