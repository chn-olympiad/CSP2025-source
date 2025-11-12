#include<bits/stdc++.h>
using namespace std;
const int N= 1e6+10;
int a[N];
const int R = 1e3+10;
int seat[R][R];
bool cnp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >> m;
	cin >> r;
	a[1] = r;
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n*m,cnp);
	int prep;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			prep = i;
			break;
		}
	}
	if(prep%n==0){
		if(prep/n%2==0){
			cout << prep/n << " " << 1 << endl;
		}else{
			cout << prep/n << " " << m <<endl;
		}
	}else{
		if(prep/n%2==0){
			cout << prep/n+1 << " " << prep%n << endl;
		}else{
			cout << prep/n+1 << " " << n-(prep%n) << endl;
		}
	}
	return 0;
}
//(/._./)   (>_<)  (>._.<)  (>x_x<)  (-_-^)  (/^._.^/)
