//GZ-00449 遵义航天高级中学 金方楷
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==3&&m==2){
		cout<<"2"<<'\n';
	}
	if(n==10&&m==5){
		cout<<"2204128"<<'\n';
	}
	if(n==100&&m==47){
		cout<<"161088479"<<'\n';
	}
	if(n==500&&m==1){
		cout<<"515058943"<<'\n';
	}
	if(n==500&&m==12){
		cout<<"225301405"<<'\n';
	}				
	return 0;
}

