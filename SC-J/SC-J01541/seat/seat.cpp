#include <bits/stdc++.h>
using namespace std;
int m4a1[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> m4a1[i];
	}
	int r=m4a1[1],idx=1;
	sort(m4a1+1,m4a1+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(m4a1[i]==r){
			idx=i;
			break;
		}
	}
	int lie=idx/n;
	if(idx%n!=0){
		lie=idx/n+1;
	}
	int hang=idx%(n*2);
	if(hang>n){
		hang=n+1-(hang%n);
	}
	cout << lie << " " << hang;
	return 0;
}