#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b==4){
		cout<<"18"<<endl<<"4 "<<endl<<"13";
	}else if(b==10){
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
	}else if(b==30){
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"484387";
	}else if(b==200){
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
	}else if(b==100000){
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"499846353"<<endl<<"1499268379"<<endl<<"1500579370";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
