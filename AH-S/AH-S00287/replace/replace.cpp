#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
long long n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}for(int i=1;i<=m;i++){
		long long cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++){
			long long t=-1;
			while((t=s1.find(a[j],t+1))!=string::npos){
				string str=s1.replace(t,a[j].size(),b[j]);
				if(str==s2){
					cnt++;
				}s1.replace(t,b[j].size(),a[j]);
			}
		}cout<<cnt<<'\n';
	}
	return 0;
}
