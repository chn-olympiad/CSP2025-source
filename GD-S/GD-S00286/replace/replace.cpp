#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int b[200010],c[200010],d[200010],e[200010],f[200010];
bool k=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s,a;
		cin>>s>>a;
		for(int j=0;j<s.size();j++){
			if(s[j]!='a'&&s[j]!='b')
				k=1;
			if(s[j]=='b')
				b[i]=j,c[i]=s.size()-j-1,f[i]=j;
		}
		for(int j=0;j<a.size();j++){
			if(a[j]!='a'&&a[j]!='b')
				k=1;
			if(a[j]=='b')
				d[i]=j,e[i]=a.size()-j-1,f[i]=f[i]-j;
		}
	}
	for(int i=1;i<=m;i++){
		if(k==1){
			for(int j=1;j<=m;j++)
				cout<<"0\n";
			return 0;
		}
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		int p=1;
		int a1,b1,c1,d1;
		for(int j=0;j<x.size();j++)
			if(x[j]=='b')
				a1=j,b1=x.size()-j-1,p=j;
		for(int j=0;j<y.size();j++)
			if(y[j]=='b')
				c1=j,d1=y.size()-j-1,p-=j;
		for(int j=1;j<=n;j++){
			if(p==f[j]&&a1>=b[j]&&b1>=c[j]&&c1>=d[j]&&d1>=e[j])
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

