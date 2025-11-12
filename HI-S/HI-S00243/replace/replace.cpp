#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N = 2e5+2;
int n,m;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fr(i,1,n)cin>>a[i]>>b[i];
	fr(i,1,m){
		string x,y;
		cin>>x>>y;
		int ans = 0;
		fr(i,1,n){
			for(int j=0;j+a[i].size()-1<x.size();j++){
				string ss = x.substr(j,a[i].size());
				if(ss==a[i]){
					string s1 = x.substr(0,j),s2 = x.substr(j+a[i].size());
					string s3 = s1+b[i]+s2;
					if(s3==y)ans++; 
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

