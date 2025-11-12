#include<bits/stdc++.h>
using namespace std;
int n,m,c[1010],a[1010],l[1010],t=0,q[1010]={0},p[1010]={0},ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=int(s[i-1])-48;
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]==a[j]){
				ans+=2;
			}
		}
	}
	cout<<ans;
	return 0;
} 
