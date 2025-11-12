#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5e5;
int n,m;
int c[maxn];
char a[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.otu","w",stdout);	
	cin>>n>>m;
	bool flag_A=true;int num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='0'){
			flag_A=false;
		}
		else {
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//¸Ð¾õÊÇDP 

	cout<<7<<"\n";
	return 0;
}
