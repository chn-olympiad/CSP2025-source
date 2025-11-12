#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t;

struct op{
	int ahc;
	bool o;
}kl[1005];

bool cmp(op a, op b){
	return a.ahc>b.ahc;
}


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin >>n >>m;
	for(int i = 1;i<=m*n;i++){
		if(i == 1){
			kl[i].o = 1;
		}
		else kl[i].o = 0;
		cin >> kl[i].ahc;
	}
	sort(kl+1,kl+1+n*m,cmp);s= 0;
	for(int i = 1;i<=m;i++){
		if(i%2 == 1){
			for(int j = 1;j<=n;j++){
				s++;
				if(kl[s].o){
					cout << i <<" "<<j;return 0;
				}
			}
		}
		else {
			for(int j = n;j>=1;j--){
				s++;
				if(kl[s].o){
					cout << i <<" "<<j;return 0;
				}
			}
		}
	}
	
	
	
return 0;
}
