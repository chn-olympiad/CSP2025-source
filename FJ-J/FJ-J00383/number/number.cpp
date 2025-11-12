#include<bits/stdc++.h>

using namespace std;
using ll=long long;

string a;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	vector<int> numc;
	for(char i:a){
		if (i-'0'>=0 && i-'0' <= 9){
			numc.push_back(i-'0');
		}
	}
	sort(numc.begin(), numc.end());
	for(int i=numc.size()-1; i>=0; i--)cout<<numc[i];
	return 0;
}

