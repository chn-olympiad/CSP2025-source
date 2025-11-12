#include <bits/stdc++.h>;
using namespace std;
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a=0,b=0,c,s={0,1};
	cin >> n >> m;
	cin >> s;
	cin >> c;
	for (int p=0; p<=n; p++){
		for (int i=0; i<=n; i++){
			if (p==i){
				int b;
				n--;
				b++;
			}
		}
	}
	for (int i=1; i<=n; i++){
		if (s==1){
			a++;
			n--;
			else if (s==0){
				n--;
				b++;
			}
		}
	}
	int c;
	if (b>c){
		n--;
		b++;
	}
	else (b<c){
		a++;
		n--;
	}
	cout << p;
	return 0;
}

