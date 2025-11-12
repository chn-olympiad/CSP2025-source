#include<bits/stdc++.h>
using namespace std;
string _str;
int num[1000010],_tmp=1;
bool _cmp(int _x, int _y){
	return _x > _y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>> _str;
	int _len=_str.size();
	for(int i=0;i<_len;i++){
		if(_str[i]<='9'&&_str[i]>='0'){
			num[_tmp++]=_str[i] - '0';
		}
	}
	sort(num+1,num+1+_tmp, _cmp);
	for(int i=1;i<_tmp;i++){
		cout<<num[i];
	}
	return 0;
}
