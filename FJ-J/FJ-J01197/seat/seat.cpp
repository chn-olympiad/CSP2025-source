#include<bits/stdc++.h>
using namespace std;
int _n,_m,_r=1, _flag;
int _mk[110];
bool _cmp(int _x, int _y){
	return _x > _y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_n>>_m;
	int _pnm=_n*_m, _indexT = 0;
	for(int i=1;i<=_pnm;i++){
		cin>>_mk[i];
	}
	int _Tm=_mk[1];
	sort(_mk+1,_mk+1+_pnm,_cmp);
	for(int i=1;i<=_pnm;i++){
		if(_mk[i]==_Tm){
			_indexT=i;
			break;
		}
	}
	for(int i=1;i<=_m;i++){
		if(i%2!=0){
			for(int j=1;j<=_n;j++){
				if(_r==_indexT){
					cout<<i<<" "<<j;
					_flag=1;
					break;
				}
				_r++;
			}
		}else{
			for(int j=_n;j>=1;j--){
				if(_r==_indexT){
					cout<<i<<" "<<j;
					_flag=1;
					break;
				}
				_r++;
			}
		}
		if(_flag){
			break;
		}
	}
	return 0;
}
