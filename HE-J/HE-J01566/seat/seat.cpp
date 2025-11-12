#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	vector<int> a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k;
			cin>>k;
			a.push_back(k);
		}
	}
	R=a[0];
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		if(R==a[i]){
			R=a.size()-i;
			break;
		}
	}
	R--;
	cout<<R/n+1<<' '<<fabs((n-1)*(R/n%2)-R%n)+1;
	return 0;
}
