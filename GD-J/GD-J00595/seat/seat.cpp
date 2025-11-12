#include<bits/stdc++.h>
using namespace std;
const int N = 1E3+7;
int n,m;
int a[N],kk,pos;
int fup(int a,int b){
	if(a%b==0) return a/b;
	return a/b+1;
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	kk=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==kk){
			pos=i;
			break;
		}
	}
	int lie=fup(pos,m),hang;
	if(lie&1){
		hang=pos%m; 
		if(hang==0) hang=n;
	} 
	else{
		hang=pos%m; 
		if(hang==0) hang=1;
		else hang=n+1-hang;
	} 
	cout << lie << " " << hang;
	return 0;
}
