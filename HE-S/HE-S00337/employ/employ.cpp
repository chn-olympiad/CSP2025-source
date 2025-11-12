#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int b[n+1];
	memset(b,0,sizeof(b));
	int count=0;
	for(int i=1;i<=n;i++){
		cin>>b[i][j];
	}
	for(int i=0;i<a.size();i++){
		if(a[i]=='0'){
			count++;
		}
	}
	cout<<n-count;
	return 0;
}
