#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a=" ";
long long c[1005];
int ooo=111;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(a[i]!=1){
			ooo=-111;
		}
	}
	if(ooo){
		cout<<0;
	}
	
	return 0;
}
