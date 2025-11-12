#include<bits/stdc++.h>

using namespace std;
using ll=long long;

bool comp_f(pair<int, int> sa1, pair<int, int> sa2){
	return sa1.second > sa2.second;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m,cache, r_index, row, column;  // n row m column
	cin >> n >> m;
	vector<pair<int, int>> sco(n*m);
	for(int i=0;i<n*m;i++){
		cin >> cache;
		sco[i] = {i, cache};
	}
	sort(sco.begin(), sco.end(), comp_f);
	for(int i=0;i<n*m;i++){
		if(sco[i].first==0){
			r_index=i;
			break;
		}
	}
	column = r_index / n;
	column+=1;
	row=r_index%n;
	if(column%2==0){
		row=n-row;
	}else{
		row+=1;
	}
	cout<<column<<" "<<row;
	return 0;
}

