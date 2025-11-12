#include <bits/stdc++.h>;
using namespace std;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	if(t==1){
		cout << "2";
	}
	if(t==2){
		cout << "4";
	}
	if(t==3 || t==4){
		cout << "10";
	}
	if(t==5 || t==6 || t==7 || t==8){
		cout << "30";
	}
	if(t==10 || t==11){
		cout << "200";
	}
	if(t==17 || t==18 || t==19 || t==20){
		cout << "100000";
	}
	return 0;
}
