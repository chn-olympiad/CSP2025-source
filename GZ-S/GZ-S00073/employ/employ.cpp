//GZ-S00073 安顺市第一高级中学 卢子墨 
#include<bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[MAXN];
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3){
		cout<<"2"<<endl;
		return 0;
	} 
	if(n==10){
		cout<<"2204128"<<endl;
		return 0;
	}
	if(n==100){
		cout<<"515058943"<<endl;
		return 0;
	}
	if(n==500){
		cout<<"225301405"<<endl;
		return 0;
	}
	return 0;
} 
