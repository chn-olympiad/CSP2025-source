#include<iostream>
#include<queue>
using namespace std;
int s=998244353;
int zg[520];
string a;
int c[520];
queue<int>q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a;
	
	for(int i=1;i<=n;i++)cin>>c[i];
	
	
	int dd=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1')dd++;
	} 
	if(dd!=a.length() and m!=1){cout<<0;return 0;}
	int g=n;
	int xy=1;
	for(int i=1;i<=n;i++){
		xy*=g;xy%=s;
		g--;
	}
	cout<<xy;
}
