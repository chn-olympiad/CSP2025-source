#include <bits/stdc++.h>
using namespace std;

bool compare(char a,char b){
	return a > b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	vector<char> NUMlist;
	string a;
	cin >> a;
	
	for (long long i = 0;i < a.size();i++){
		char x = a[i];
		int Num = x - '0';
		if (Num >= 0 && Num <= 9){
			NUMlist.push_back(x);
		}
	}
	
	sort(NUMlist.begin(),NUMlist.end(),compare);
	for(char a:NUMlist) cout << a;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
