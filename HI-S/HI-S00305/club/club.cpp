#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,num,ans,num1,num2,num3;
long long a[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n;
	cin >> m;
	if(m % 2 == 1){
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> num1 >> num2 >> num3; 
			x += max(num1,max(num2,num3));
		}
		cout << x;
	}
	return 0;
} 
