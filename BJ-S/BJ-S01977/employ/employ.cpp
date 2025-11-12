#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,num=0,ans=1;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a){
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		ans*=(n-i+1);
		ans%=998244353;
	}
}
