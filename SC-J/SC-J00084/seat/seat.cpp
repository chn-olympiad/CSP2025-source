#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n, m, a[N];

bool cmp(int& A,int& B){
	return A > B;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}
	
	int tmp = a[1];
	
	sort(a+1, a+n*m+1, cmp);
	
	int pos = 0;
	//名次 
	
	for(int i=1;i<=n*m;++i){
	//	cout << a[i] <<" ";
		if(a[i] == tmp){
			pos = i;
			break;
		}
	}
	
	int r = 0,c = 1,d = 1;
	while(pos){
		pos -= 1;
		r += d;
		if(r > n){
			r = n;
			c++;
			d *= (-1);
		}
		if(r < 1){
			r = 1;
			c++;
			d *= (-1);
		}
		//cout << "位置: " << c << r << endl;
	}
	cout << c << " " << r << endl;
	
	return 0;
}