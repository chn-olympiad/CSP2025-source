#include<bits/stdc++.h>
using namespace std;

int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}
	int my = a[1];
	int x;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;++i){
		if(a[i] == my){
			x = i;
			break;
		} 
	}
	
	int lie = x/m + (x%m>0);
	cout<<lie<<" ";
	
	int n_x = x-((lie-1) * m);
	
	if(lie%2 == 1) cout<<n_x;
	else cout<<m-n_x+1;
	
	return 0;
}
