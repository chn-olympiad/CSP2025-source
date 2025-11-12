#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
struct node{
	string str1,str2;
}s[N];
int ans=0;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].str1>>s[i].str2;
	}
	while(q--){
		cin>>a>>b;
		ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0,z=0; 
			while(a.find(s[i].str1,z+1)!=string::npos){
				cnt=a.find(s[i].str1,z+1);
				z=cnt;
				for(int j=0;j<s[i].str2.size();j++){
//					cout<<1;
					a[j+cnt]=s[i].str2[j];
				}
				if(a==b){
					ans++;
				}
				for(int j=0;j<s[i].str1.size();j++){
					a[j+cnt]=s[i].str1[j];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
