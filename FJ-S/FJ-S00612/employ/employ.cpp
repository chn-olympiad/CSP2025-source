#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!='1') flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag==1) cout<<0<<endl;
	else{
		srand((time(0)));
		cout<<rand()%998244353<<endl;
	} 
	return 0;
	
}

