#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n,m;
int grade[N];
int s;
int ansa = 1,ansb = 1;
int cnt = 1;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a = n * m;
	for(int i = 1; i <= a; i++)
		scanf("%d",&grade[i]);
	s = grade[1];
	sort(grade + 1,grade + 1 + a,cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(grade[cnt] == s){
				printf("%d %d",ansb,ansa);
				return 0;
			}
			cnt++;
			if(ansb % 2){
				ansa++;
				if(ansa > n){
					ansb++;
					ansa = n;
				}
			}else{
				ansa--;
				if(ansa <= 0){
					ansa = 1;
					ansb++;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1.
2 2
99 100 97 98
2.
2 2
98 99 100 97
3.
3 3
94 95 96 97 98 99 100 93 92
*/
