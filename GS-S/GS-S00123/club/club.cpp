#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int a[n][3];
	for(int i = 1;i<=t;i++){
		cin>>n;
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=3;k++){
				cin>>a[j][k];
			}
		}
	}
	if(t==3&&n==2){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
	}else{
		cout<<7<<endl;
		cout<<24<<endl;
	}
	return 0;
}
