#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int t,n;
int d[N][10];
int mx[N],mx1[N];
int num[10];
int ans[N];

int main(){
	scanf("%d",&t);
	
	for(int x = 0; x < t; x++){
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			for(int k = 1;k <= 3; k++) scanf("%d",&d[j][k]);
		} 

		int flag = 0;
		int flag1 = 0;
		int a = 0,j = 1;
		for(int i = 0; i < n; i++){
			a = 0;
			for(int j = 1; j <= 3; j++){
			
				if(d[i][j] > a){
					a = d[i][j];
					flag1 = j;
				}
			}
			mx[flag] = a;
			mx1[flag] = flag1;
			flag++;
			num[flag1]++;

		}
		
		a = 0;
		for(int i = 0; i < n; i++){
			if(mx[i] > a){
				a = mx[i];
				flag1 = mx1[i];
			}
		}

		for(int i = 0; i < n; i++){
			ans[x] += mx[i];
		}

		
	}
	
	for(int i = 0; i < t; i++) cout << ans[i] << endl;
	return 0;
}
