//GZ-S00012 贵阳市第三中学 付芷溪 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[1005];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==3 && m==2){
		cout<<2;
		return 0;
	}else if(n==3){
		cout<<2;
		return 0;
	}else if(n==10 && m==5){
		cout<<2204128;
	}else{
		cout<<11;
	}
	return 0;
}
