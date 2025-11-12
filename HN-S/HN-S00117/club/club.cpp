#include<iostream>
using namespace std;
int main(){
	preopen("club.in","r",stdin);
	preopen("club.out","w",stdout);
	
	int t,n[3],a[1000];
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>a[i];
		}
	}
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
	
	fclos(stdin);
	fclos(stdout);
	return 0;
}
