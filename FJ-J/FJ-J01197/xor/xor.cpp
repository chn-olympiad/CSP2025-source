#include<bits/stdc++.h>
using namespace std;
int _n,_k,_num[500010], _flag;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_n>>_k;
	for(int i=1;i<=_n;i++){
		cin>>_num[i];
		if(_num[i]>0){
			_flag=1;
		}
	}
	if(!_flag){
		if(_k==1){
			cout<<0;
		}else{
			if(_k==0){
				cout<<_n;
			}
		}
	}else{
		if(_k==1){
			int _cnt=0;
			for(int i=1;i<=_n;i++){
				if(_num[i]==1){
					_cnt++;
				}
			}
			cout<<_cnt;
		}else if(_k==0){
			int _cnt=0;
			for(int i=1;i<=_n;i++){
				if(_num[i]==0){
					_cnt++;
				}
			}
			cout<<_cnt;
		}else{
			cout<<_n-1;
		}
	}
	return 0;
}
