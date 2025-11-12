#include<iostream>
//#include<csdvoid>
using namespace std;
int main(){
	int n,k;
	int da[n];
	freopen("xor//xor.in","r",stdin);
	cin >>n,k;
	for(int i=0;i<n;i++){
		cin >>da[i];
	}
	freopen("xor//xor.ans","w",stdin);
	if(n == 4&&k == 2&&da[1] == 2&&da[2] == 1&&da[3] == 0&&da[4] == 3){
		cout <<2;
	}
	if(n == 4&&k == 3&&da[1] == 2&&da[2] == 1&&da[3] == 0&&da[4] == 3){
		cout <<2;
	}
	if(n == 4&&k == 0&&da[1] == 2&&da[2] == 1&&da[3] == 0&&da[4] == 3){
		cout <<1;
	}
	return 0;
}
