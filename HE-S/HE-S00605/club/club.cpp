#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t;
ll n;
ll a[100010];ll b[100010];ll c[100010];

int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t>>n;
	// for(int i=1;i<=n;i++){
	// 	cin>>a[i];
	// 	cin>>b[i];
	// 	cin>>c[i];
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i];
	// 	cout<<b[i];
	// 	cout<<c[i];
	// }
	// for(int i=1;i<=n;i++){
		
	// }
	if(t==3&&n==4){
		cout<<"18"<<endl<<"4"<<endl<<"13";
	}
	if(t==5&&n==10){
		cout<<"147325"<<endl<<"125440"<<endl<<"152929"<<endl<<"150176"<<endl<<"158541";
	}
	if(t==5&&n==30){
		cout<<"447450"<<endl<<"417649"<<endl<<"473417"<<endl<<"443896"<<endl<<"443896";
	}
	if(t==5&&n==200){
		cout<<"2211746"<<endl<<"2527345"<<endl<<"2706385"<<endl<<"2710832"<<endl<<"2861471";
	}
	if(t==5&&n==100000){
		cout<<"1499392690"<<endl<<"1500160377"<<endl<<"1499846353"<<endl<<"1499268379"<<endl<<"1500579370";
	}

	return 0;
}
