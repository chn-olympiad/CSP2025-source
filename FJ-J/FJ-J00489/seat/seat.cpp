#include<bits/stdc++.h>
using namespace std;
int n,m,judge;
int grade[101],r_gra;
bool cmp(int a,int b){
	return a > b;
}
int main(){//先列再行 
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&r_gra);grade[1] = r_gra; 
	for(int i = 2;i <= n * m; i++)cin >> grade[i];
	sort(grade + 1,grade + 1 + n * m , cmp);
	for(int i = 1;i <= n * m; i++)if(grade[i] == r_gra)judge = i;

	if(judge <= n)cout << 1 << ' ' << judge;
	else{
		if((judge%n) == 0){
			if((judge / n)%2==0) cout << judge /n << ' ' << 1;
			else cout << judge / n << n;
		}
		else if((judge/n + 1)%2==1) 
			cout << (judge/n + 1) << ' ' << judge % n;
		else cout << (judge/n + 1) << ' '<< n - (judge % n) + 1 ;
	}
	return 0;
} 
