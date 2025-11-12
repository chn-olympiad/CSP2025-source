#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int a[10086];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++){
		cin>>a[i];
	}
	int s = a[1];
	sort(a+1,a+n*m+1);
	bool z = true;
	int q = 1,v = n,e = n,u = 1;
	for(int i = m; i >= 1; i--){
		if(z == true){
			if(i % 2 != 0){
				int t = 1;
				for(int j = q; j <= v; j++){
					if(a[j] == s){
						cout<<i<<" "<<t;
						z = false;
						break;
					}
					t++;
				}
				q = v;
				v = v + n;
				u = e;
				e = e + n;
			}
			else{
				int y = n;
				for(int j = e; j >= u; j--){
					if(a[j] == s){
						cout<<i<<" "<<y;
						z = false;
						break;
					}
					y--;
				}
				u = e;
				e = e + n;
				q = v;
				v = v + n;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
