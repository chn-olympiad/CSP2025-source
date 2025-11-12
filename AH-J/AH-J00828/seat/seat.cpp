#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],rsc,hang,lie=1,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m >> a[1];
	rsc=a[1];
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(d==0){
			hang++;
			if(hang==n)d=1;
		}
		else if(d==1){
			lie++;
			d=2;
		}
		else if(d==2){
			hang--;
			if(hang==1)d=3;
		}
		else{
			lie++;
			d=0;
		}
		if(a[i]==rsc){
			cout << lie << " " << hang;
			return 0;
		}
	}
	return 0;
}
