#include<iostream>
using namespace std;
int m,n,g,l,c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> g;
	for(int i = 0;i < m*n-1;i++){
		cin >> l;
		if(l > g){
			if(c%2 == 1){
				r++;
				if(r > n){r = n;c++;}
			}else{
				r--;
				if(r < 1){r = 1;c++;}
			}
		}
	}
	cout << c << " " << r << endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
