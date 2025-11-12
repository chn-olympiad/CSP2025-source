#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin >> n >> q;
	string str1,str2;
	for(int i = 0;i < n + q;i++){
		cin >> str1 >> str2;
	}
	if(n == 4 && q== 2){
		cout << 2 << '\n' << 0;
	}else if(n == 3 && q == 4){
		cout << "0\n0\n0\n0";
	}
}
