#include<bits/stdc++.h>
using namespace std;
int n,m,grade,lie,hang;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	grade = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(i%n==0){
			lie = i/n;
		}else{
			lie = i/n+1;
		}
		if(lie%2==1){
			hang = i-(lie-1)*n;
		}else{
			hang = lie*m+1-i;
		}
		if(a[i]==grade) cout << lie << " " << hang;
	}
	return 0;
}