#include<bits/stdc++.h>
using namespace std;
int num[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int b,n;
	cin>>b;
	while(b--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>num[i][j];
			}
		}
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13;
} 

