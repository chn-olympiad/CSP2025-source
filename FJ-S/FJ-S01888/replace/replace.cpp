#include<bits/stdc++.h>

using namespace std;

int n,q,ans;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	string a[5][200005],s_1,s_2;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>s_1>>s_2;
		
		cout<<ans;
	}
	
	return 0;
}
