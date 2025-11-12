#include <bits/stdc++.h>
using namespace std;
const int maxn = 250;
int n,m;// n-hang m-lie
int a[maxn];
int c,r;//c-lie r-hang
int cmp(int a1, int a2){
	return a1>a2;
}
int mp[maxn][maxn];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	int nm = n*m;
	for(int i=1; i<=nm; i++){
		cin>>a[i];
	}
	int Rg = a[1];
	int numR = 1;
	sort(a+1, a+nm+1, cmp);
	for(int i=1; i<=nm; i++){
		if(Rg == a[i]){numR = i; break;}
	}
	
	int k = 1;
	
	for(int i=1; i<=m; i++){
		
		if(i%2 != 0){
			int j=1;
			while(j<=n){
				if(a[k] != Rg){
					k++;
				}
				else{
					c = i;
					r = j;
					cout<<c<<" "<<r<<endl;
					return 0;
				}
				j++;
			}
		}
		else{
			int j = n;
			while(j>=1){
				if(a[k] != Rg){
					k++;
				}
				else{
					c = i;
					r = j;
					cout<<c<<" "<<r<<endl;
					return 0;
				}
				j--;
			}
		}
	}
	
	/*if(n<=1){
		if(m<=1){
			c = m;
			r = n;
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
	if(n<=2){
		if(m<=2){
			bool flagA = true;
			bool flagB = true;
			
			for(int i=1; i<=n*m; i++){
				if(a[i] != i) flagA = false;
				if(a[i] != nm - i + 1) flagB = false;
			}
			if(flagA){
				if(numR == 1){
					cout<<1<<" "<<1<<endl;
					return 0;
				}
				if(numR == 2){
					cout<<1<<" "<<2<<endl;
					return 0;
				}
				if(numR == 3){cout<<2<<" "<<1<<endl; return 0;}
				if(numR == 4){cout<<2<<" "<<2<<endl; return 0;}
			}
			if(flagB){
				
			}
		}
	}*/
	return 0;
}
//#Shang4Shan3Ruo6Shui4
