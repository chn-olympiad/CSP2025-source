#include<bits/stdc++.h>
using namespace std;
string a;
int qql,wwl;
bool bo;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int al = a.size();
	int qq[al] = {0},ww[al] = {0};
	for(int i = 0;i < al;i ++){
		if(a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9'){
			qq[qql] = a[i] - '0';
			qql ++;
		}
	}
	sort(qq,qq + qql);
	for(int i = al - 1;i >= 0;i --){
		ww[wwl] = qq[i];
		wwl ++;
	} 
	for(int i = 0;i < al;i ++){
		if(ww[i] != 0){
			for(int j = i;j < al;j ++) cout << ww[j];
			break;
		}
	}
	return 0;
}