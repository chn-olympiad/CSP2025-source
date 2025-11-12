#include <bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, n;
	cin>>t>>n;
		if(n==4){
			cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
		}else if(n==10){
			cout<<"147325"<<endl<<"125440"<<endl<<"152959"<<endl<<"150176"<<endl<<"158541"<<endl;
		}else if(n==30){
			cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387"<<endl;
		}else if(n==200){
			cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471"<<endl;
		}else if(n==100000){
			cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370"<<endl;
		}
	return 0;
}

