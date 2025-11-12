#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string t1,t2,s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			if(t1.find(s[j][0])==t2.find(s[j][1])&&t1.find(s[j][0])!=0){
				ans++;
			}
		}
		cout<<ans;
	}
}
