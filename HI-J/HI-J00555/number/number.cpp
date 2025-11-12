#include<bits/stdc++.h>
using namespace std;
string n;
int m;
int a,b,c,d,e,f,g,h,o,p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n.size();i++){
		if(n[i]=='9'){
			a++;
		}else if(n[i]=='8'){
			b++;
		}else if(n[i]=='7'){
			c++;
		}else if(n[i]=='6'){
			d++;
		}else if(n[i]=='5'){
			e++;
		}else if(n[i]=='4'){
			f++;
		}else if(n[i]=='3'){
			g++;
		}else if(n[i]=='2'){
			h++;
		}else if(n[i]=='1'){
			o++;
		}else if(n[i]=='0'){
			p++;
		}
	}
	for(int i = 1;i<=a;i++){
		cout << 9;
	}for(int i = 1;i<=b;i++){
		cout << 8;
	}for(int i = 1;i<=c;i++){
		cout << 7;
	}for(int i = 1;i<=d;i++){
		cout << 6;
	}for(int i = 1;i<=e;i++){
		cout << 5;
	}for(int i = 1;i<=f;i++){
		cout << 4;
	}for(int i = 1;i<=g;i++){
		cout << 3;
	}for(int i = 1;i<=h;i++){
		cout << 2;
	}for(int i = 1;i<=o;i++){
		cout << 1;
	}for(int i = 1;i<=p;i++){
		cout << 0;
	}
	return 0;
}
