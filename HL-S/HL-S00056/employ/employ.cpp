#include<bits/stdc++.h> 
#define ull unsigned long long
using namespace std;
ull m,n;
ull ma=1;
int c[550],s[505];
string ss;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=ss.size();i++){
		s[i]=(int) ss[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1)	ma=n;
	if(m==n){
		for(int i=1;i<=m;i++){
			ma=ma*(i%998244353);
		}
	}
	cout<<ma;
	return 0;
}
