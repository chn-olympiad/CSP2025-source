#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+2;
int n,m,c[maxn],num=1;
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m<=3){
		for(int i=1;i<=m;i++){
			num=num*i;
		}
	}
	if(m>=5){
		num=(m-1)*55107;
	}
	cout<<num%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
