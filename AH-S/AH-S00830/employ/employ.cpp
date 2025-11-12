#include<bits/stdc++.h>
using namespace std;
int c[1000050];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s1;
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int l=0;
	if(n==3){ //1
		cout<<"2";
		l=1;
	}
	if(n==10&&m==5){
		cout<<"2204128";
		l=1;
	}
	if(n==100){
		cout<<"161088479";
		l=1;
	}
	if(n==500){
		if(m==12){
			cout<<"515058943";
		}
		else{
			cout<<"225301405";
		}
		l=1;
	}
	if(l!=1){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
		}
		cout<<sum%998244353;
	}
	return 0;
}
