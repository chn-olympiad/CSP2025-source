#include<bits/stdc++.h>
using namespace std;

int mark[300];
int countt;
int n,m;//n行m列 
//单数列向下，双数列向上 

bool tmp(int a,int b){
	return a > b;
}

int find(int need){
//	cout << "here is R(need):"<< need << "\n";
	for(int i = 0;i < countt;i++){
		if(mark[i] == need){
//			cout << "here is i:"<< i << "\n";
//			cout << "here is i+1(return number):"<< i+1 << "\n";
			return i+1;
		}
	}
	return 0;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	countt = n*m;
	
	for(int i = 0;i < countt;i++){
		cin >> mark[i];
	}
	int R = mark[0];
	sort(mark,mark+countt,tmp);
	
//	for(int i = 0; i < countt;i++){
//		cout << i << ":" << mark[i] << "\n";
//	} 
	int Rseat = find(R);
//	cout << Rseat;

	//n行m列 
	//单数列向下，双数列向上
	int x,y;//x:行,y:列
	if(Rseat%n == 0){
		y=Rseat/n;
		if(y%2==0){
			cout << y << " " << 1;
		}
		else{
			cout << y << " " << n;
		}
	}
	else{
		y=Rseat/n+1;
		int sheng;
		if(y%2==0){
			cout << y << " " << n+1-(Rseat-(Rseat/n)*n);
		}
		else{
			cout << y << " " << (Rseat-(Rseat/n)*n);
		}
	}
	return 0;
}

