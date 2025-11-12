#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600005];
int ansl[600005];
int ansr[600005];
int s;
int cnt=0;
bool b=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
		if(!b) s=a[i];
		else s^=a[i];
		b=true;
		if(s==m){
			cnt++;
			b=false;
		}
	}
	cout<<cnt;
	return 0;
}
