#include<bits/stdc++.h>
using namespace std;

int n,q;
struct str{
	int l,r,x;
}a[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		int b1,b2;
		bool f1=0,f2=0;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b')b1=j,f1=1;
			if(s2[j]=='b')b2=j,f2=1;
			if(f1&&f2)break;
		}
		a[i].l=b1;
		a[i].r=s1.size()-1-b1;
		a[i].x=b2-b1;
	}
	while(q--){
		int ans=0;
		string t1,t2;
		int b1,b2,l,r,x;
		bool f1=0,f2=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<'\n';continue;}
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b')b1=i,f1=1;
			if(t2[i]=='b')b2=i,f2=1;
			if(f1&&f2)break;
		}
		l=b1,r=t1.size()-1-b1,x=b2-b1;
		for(int i=1;i<=n;i++)
			if(l>=a[i].l&&r>=a[i].r&&x==a[i].x)ans++;//cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].x<<endl;
		cout<<ans<<'\n';
	}
	return 0;
}

