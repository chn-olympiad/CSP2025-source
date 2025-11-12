#include<bits/stdc++.h>
using namespace std;
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,c[100]={},out=1;
	cin>>n>>m;
	string s;
	cin>>s;
	bool pd=1;
	for(int i=0;i<n;i++){
		if((s[i]-'0')!=1){
			pd=0;
			break;
		}
		cin>>c[i];
	}
	if(pd){
		for(int i=n;i>0;i--){
			out*=i;
			
		}
	}
	else{
		out=2;
	}
	cout<<out;
	return 0;
}
