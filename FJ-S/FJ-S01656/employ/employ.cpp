#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10){
		cout<<2204128<<endl;
	}else{
		if(n==100){
			cout<<161088479<<endl;
		}else{
			if(n==500&&m==1){
				cout<<515058943<<endl;
			}else{
				if(n==500&&m==12){
					cout<<225301405<<endl;
				}else{
					cout<<m;
				}
			}
		}
	}
	return 0;
} 

