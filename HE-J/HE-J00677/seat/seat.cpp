#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=(n*m);i++){
		cin >> a[i];
	}
	s=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int p=1;
	int q=1;
	bool f=true;
	for (int i=1;i<=(n*m);i++){
		if (a[i] != s){
			if (f == true){
				if (p != n){
					p+=1;
				}else{
					q+=1;
					f = false;
				}	
			}else{
				if (p != 1){
					p-=1;
				}else{
					q+=1;
					f = true;
				}
			}
		}else{
			cout << q << " " << p;
			break;
		}
	}
	return 0;
}
