#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> v(n*m);
	for(int i=0; i<n*m; i++){
		cin >> v[i];
	}
	int r=v[0];
	sort(v.begin(),v.end(),greater<int>());
	int j,f=0;
	for(int i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(v[f]==r){
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
			f++;
		}
		i++;
		for(j=n-1; j>=0; j--){
			if(v[f]==r){
				cout << i+1 << " " << j+1 << endl;
				return 0;
			}
			f++;
		}
	}
	return 0;
}
