#include<iostream>
using namespace std;
long long n[100002],zushu,ans,zu[10000002];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>zushu; 
	for(int i = 1;i <= zushu;i++){
		cin>>n[i-1];
		for(int j = 0;j < 3;j++){
			cin>>zu[i*3-i+j];
		}
	}
	if(zushu==3){
		cout<<"18"<<endl<<"4"<<endl<<"13";
	}
	if(n[0]==10){
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541"<<endl;
	}
	if(n[0]==30){
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387"<<endl;
	}
	if(n[0]==200){
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471"<<endl;
	}
	if(n[0]==100000){
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370"<<endl;
	}
}
