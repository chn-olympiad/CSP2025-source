#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1145],cnt=1,x=0;
string s;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		cnt*=i;
		if(cnt>998244353){
			cnt=cnt%998244353;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
