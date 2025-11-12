#include<iostream>
using namespace std;

int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	int pi[100]={},zi[100]={},wi[100]={};
	cin>>n>>m>>k;
	int c[1000]={},s[1000]={};
	for(int i=1;i<=n;i++){
		cin>>pi[i]>>zi[i]>>wi[i];
		cnt+=wi[i];
	}
	cout<<cnt; 
	return 0;
	
}
