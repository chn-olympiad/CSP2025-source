#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sqqqv;
	cin >> sqqqv;
	char aqqqv[1000005]={0};
	int sumaqqqv=1;
	for(int iqqqv=0;iqqqv<sqqqv.size();iqqqv++){
		if(sqqqv[iqqqv]>='0'&&sqqqv[iqqqv]<='9'){
			aqqqv[sumaqqqv]=sqqqv[iqqqv];
			sumaqqqv++;
		}
	}
	sort(aqqqv+1,aqqqv+sumaqqqv+1);
	for(int iqqqv=sumaqqqv;iqqqv>=1;iqqqv--){
		cout << aqqqv[iqqqv];
	}
	return 0;
} 
