#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int hard[11],a[15];
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		hard[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int jc[12]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
	for(int i=1;i<=jc[n];i++){
		int j=i,shunxu[11];
		bool vis[11];
	}
	cout<<0;
	return 0;
}

