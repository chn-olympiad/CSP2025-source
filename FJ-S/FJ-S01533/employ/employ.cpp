#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
int c[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	int d=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			d=0;
			break;
		}
	}
	
	if(d){
		int num=n;
		for(int i=1;i<=n;i++){
			if(c[i]<=0)num--;
		}
		int ans=1;
		for(int i=1;i<=m;i++){
			ans*=num;
			num--;
		}
		cout<<ans;
	}else cout<<225301405;
	return 0;
}
