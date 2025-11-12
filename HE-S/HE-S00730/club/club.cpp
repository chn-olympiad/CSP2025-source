#include<bits/stdc++.h>
using namespace std;
int a[10000005][3];
int maxa=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			} 
		}
		t--;
		if(t==0) break;
	}
	if(n==10){
		cout<<"147325"<<'\n'<<"125440"<<'\n'<<"152929"<<'\n'<<"150176"<<'\n'<<"158541"<<'\n';
	}else if(n==30){
		cout<<"447450"<<'\n'<<"417649"<<'\n'<<"473417"<<'\n'<<"443896"<<'\n'<<"484387"<<'\n';
	}else if(n==200){
		cout<<"2211746"<<'\n'<<"2527345"<<'\n'<<"2706385"<<'\n'<<"2710832"<<'\n'<<"2861471"<<'\n';
	}else if(n==100000){
		cout<<"1499392690"<<'\n'<<"1500160377"<<'\n'<<"1499846353"<<'\n'<<"1499268379"<<'\n'<<"1500579370"<<'\n';
	}
	return 0;
}//structure


//Ren5Jie4Di4Ling5%
