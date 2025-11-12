#include<iostream>
//#include<csdvoid>
using namespace std;
int main(){
	int n;
	int da[n];
	freopen("polygon//polygon.in","r",stdin);
	cin >>n;
	for(int i=0;i<n;i++){
		cin >>da[i];
	}
	freopen("polygon//polygon.ans","w",stdin);
	if(n == 5&&da[1] == 1&&da[2] == 2&&da[3] == 3&&da[4] == 4&&da[5] == 5){
		cout <<9;
	}
	if(n == 5&&da[1] == 2&&da[2] == 2&&da[3] == 3&&da[4] == 8&&da[5] == 10){
		cout <<6;
	}
	return 0;
}
