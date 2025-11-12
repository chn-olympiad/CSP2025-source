#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,q;
string a,b;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	f(i,1,n){
		cin>>a>>b;
		mp[a]=b;
	}f(i,1,q){
		int cnt=0;
		cin>>a>>b;
		int x=0,y=0;
		f(i,0,a.size()-1){
			if(a[i]!=b[i]){
				if(x==0)x=i;
				y=i;
			}
		}
		f(s,0,x){
			f(e,y,a.size()-1){
				if(mp[a.substr(s,e-s+1)]==b.substr(s,e-s+1))cnt++;
			}
		}cout<<cnt<<"\n";
	}
}
