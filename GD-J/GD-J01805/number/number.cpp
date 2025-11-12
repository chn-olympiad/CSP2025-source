#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	cin >> a;
	for(int i = 0;i < (int)a.size();i++){
		if(a[i] <= '9' and a[i] >= '0'){
			b += a[i];
		}
	}
	sort(b.begin(),b.end(),cmp);
	cout<<b;
	return 0;
}
