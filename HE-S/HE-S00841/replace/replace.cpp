#include <bits/stdc++.h>
using namespace std;
map<string,string>Map;
int n,p;
string s,t;
string jie(int l,int r){
	if(l>r)return "";
	string x="";
	for(int i=l;i<=r;i++)x+=s[i];
	return x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		Map[s]=t;
	}
	for(int i=1;i<=p;i++){
		int sum=0;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		int n=s.size();
		for(int d=2;d<=n;d++){
			for(int i=0;i+d-1<n;i++){
				int j=i+d-1;
				string ans=jie(0,i-1)+Map[jie(i,j)]+jie(j+1,n-1);
				if(ans==t)sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//hope 25
