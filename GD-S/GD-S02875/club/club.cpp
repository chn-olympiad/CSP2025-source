#include <bits/stdc++.h>
using namespace std;

int t,n;
int a,b,c,o;
int num[10001],ans[10001];
int main(){
	//freopen("clud.in","r",stdin);
	//freopen("clud.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++){
		 cin>>n;
		 int m=n/2;
		 for(int i=1;i<=n;i++){
		 	cin>>a>>b>>c;
		 	num[k]+=max(a,max(b,c));
		}
	}
	for (int k=1;k<=t;k++){
		 cout<<num[k]<<endl;
	}
	return 0;
}
