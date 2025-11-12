#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct th{
	string x,y;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		string s1,s2;
		ll ans=0;
		cin>>s1>>s2;
		int dq=0;
		for(int i=1;i<=n;i++){
			int k=s1.find(a[i].x);
			string asdf=a[i].x;
			int le=asdf.size();
			if(a[i].x==s1){
                if(a[i].y==s2)ans++;
                continue;
			}
			if(k==-1||s1.size()!=s2.size())continue;
			dq=k;
			//cout<<k<<endl;
			string sk=s1;
			while(k!=-1){
                string s;
				if(k+le<s1.size()-1)s=s1.replace(k,k+le-1,a[i].y);
				else s=s1.replace(k,k+le-2,a[i].y);
				if(s==s2)ans++;
				k=s1.find(a[i].x,dq+1);
				dq=k;
				s1=sk;
				//cout<<s<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
