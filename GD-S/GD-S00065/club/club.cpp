#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;++i){
		int n;
		cin >> n;
		vector<int> fst(n),scd(n),thrd(n);
		for(int j=0;j<n;++j){
			cin >> fst[j] >> scd[j] >> thrd[j];
		}
		sort(fst.begin(),fst.end());
		reverse(fst.begin(),fst.end());
		int sum=0;
		for(int i=0;i<n/2;++i){
			sum+=fst[i];
		}
		cout << sum;
	}
	return 0;
}
