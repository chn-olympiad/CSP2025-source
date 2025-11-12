#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int n,q;
string a,b,x,y,d[N];
map<string,bool>vis;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		vis[a]=1;
		mp[a]=b;
	}
	for(int t=1;t<=q;t++){
		int sum=0;
		cin>>x>>y;
		int len=x.size();
		d[len]="";
		for(int i=len-1;i>=0;i--)d[i]=x[i]+d[i+1];
		string s="",mid;
		for(int i=0;i<len;i++){
			mid="";
			for(int j=i;j<len;j++){
				mid=mid+x[j];
				if(vis[mid]){
					if(s+mp[mid]+d[j+1]==y)sum++;
				}
			}s=s+x[i]; 
		}cout<<sum<<endl;
	}
	return 0;
} 
