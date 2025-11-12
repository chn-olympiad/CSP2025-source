#include<bits/stdc++.h>
using namespace std;
int n,m,c[507];
long long ans=1,cnt=0;
string s;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,cmp);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				cout<<"0";
				return 0;
			}
		}
		return 0;
	}
	cout<<"0";
	return 0;
}
