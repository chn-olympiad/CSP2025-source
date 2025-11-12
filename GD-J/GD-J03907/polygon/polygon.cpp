#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t,a[1005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n == 3){
		for(int i =1;i<=n;i++){
		cin >>a[i];s+=a[i];}
		m = max(a[1],a[2]);
		m = max(m,a[3]);
		m = m*2;
		if(s>=m)cout <<1;
		else cout <<0;
		return 0;
	}
	if(n<3)cout <<0;
	
	return 0;
}
