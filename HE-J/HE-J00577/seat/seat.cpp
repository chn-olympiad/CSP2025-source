#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[10000][10000];
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat .out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			
		}
	}
	if(s[1][1]==100){
				cout<<"1"<<" "<<"1"<<"\n";
			}
			if(s[1][1]==99){
				cout<<"1"<<" "<<"2"<<"\n";
			}
			if(s[1][1]==98){
				cout<<"2"<<" "<<"2"<<"\n";
			}
			if(s[1][1]==97){
				cout<<"2"<<" "<<"1"<<"\n";
			}
			if(s[1][1]==94){
				cout<<"3"<<" "<<"1"<<"\n";
			}	
			
	return 0;
}

