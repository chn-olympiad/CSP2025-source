#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sc[10010];
int n,m,a;

bool cmp(int a , int b){
	return a > b;
}
void solve()
{
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> sc[i];
	}
	a = sc[1];
	sort(sc+1,sc+(n*m)+1,cmp);
	
	ll num;
	for(int i = 1;i<=n*m;i++){
		if(a == sc[i]){
			num = i;
			break;
		}
	}
	
	ll lie;
	if(num / n * n < num) lie = num/n+1;
	else lie = num/n;
	ll hang;
	if(lie & 1){
		hang = num - (lie - 1) * n;
	}
	else {
		hang = n-(num - (lie - 1) * n) + 1;
	}
	cout << lie << ' ' << hang; 
	

}

int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	solve();
	return 0;
}

