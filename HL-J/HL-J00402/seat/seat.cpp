#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int>grades;
	int m,n;
	int g;
	cin >> n >> m;
	int a;
	cin >> a;
	grades.push_back(a);
	for(int i = 1;i<n*m;i++){
		cin >> g;
		grades.push_back(g);
	}
	sort(grades.begin(),grades.end(),greater<int>());
	int index;
	for(int i=0;i<grades.size();i++){
		if(grades[i-1]>a && a>grades[i+1]){
			index = i;
			break;
		}
	}
	int x = floor(index/n) + 1;
	int y;
	if(x%2==0){
		y = n-(index%n);
	}
	else{
		y = index%n + 1;
	}
	cout << x<<" " << y;
	return 0;
}
