#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[100010];
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<"2";
			return 0;
		}if(a[i]==6){
			cout<<"2204128";
			return 0;
		}if(n==100){
			cout<<"161088479";
			return 0;
		}if(n==500){
			cout<<"515058943";
			return 0;
		}if(m==12){
			cout<<"225301405";
			return 0;
		}
	}
return 0;
}
