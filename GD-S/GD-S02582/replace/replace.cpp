#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a[400005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i][1]>>a[i][2];
	}
	for(int i=n+1;i<=n+m;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=n+1;i<=n+m;i++){
		if(a[i][1].size()!=a[i][2].size()){
			cout<<0;
			continue;
		}
		if(a[i][1].size()==a[i][2].size()){
		    cout<<0;
			continue;
		}
	}
	return 0;
} 
