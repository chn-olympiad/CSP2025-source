#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int a,b;
	cin >> a >> b;
	vector<int> x;
	for(int i=0;i<a*b;i++){
		int f;
		cin >> f;
		x.push_back(f);
	}
	int r = x[0];
	sort(x.begin(),x.end());
	vector<int> y;
	for(int i=x.size()-1;i>=0;i--){
		y.push_back(x[i]);
	}
	for(int i=0;i<y.size();i++){
		if(r == y[i]){
			i++;
			int d = ceil(i/double(a));
			cout << d << ' ';
			if(d%2 == 1){
				cout << i-(d-1)*a;
			}
			else{
				cout << b-i+(d-1)*a;
			}
			break;
		}
	}
	return 0;
}
