#include<bits/stdc++.h>
using namespace std;

int n,m,a[150],r,t,b=1,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	t=a[0];
	sort(a,a+(n*m));
	for(int i=n*m-1;i>=0;i--){
		
		if(a[i]!=t){
			r++;
			//cout << a[i] << " " << t << " " << r << endl;
		}else break;
		//cout << r << endl;
	}
	for(int i=0;i<r;i++){
		if(c%2==1){
			if(b==n){
				c++;
				//cout << c << " " << "c1" << endl;
			}else{
				b++;
				//cout << b << " " << "b1" << endl;
			}
		}else{
			if(b==1){
				c++;
				//cout << c << " " << "c2" << endl;
			}else{
				b--;
				//cout << b << " " << "b2" << endl;
			}
		}
	}
	cout << c << " " << b;
	return 0;
}
