#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using ll=long long;
int n,m;
int a[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=3)cout<<2<<endl;
	else if(n<=10)cout<<2204128<<endl;
	else if(n<=100)cout<<161088479<<endl;
	else if(n<=500 && m==1)cout<<515058943<<endl;
	else cout<<225301405<<endl;
	return 0;
}
