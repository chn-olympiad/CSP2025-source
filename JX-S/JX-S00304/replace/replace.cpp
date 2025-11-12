#include<bits/stdc++.h>
using namespace std;
int n,q,len1,len2,l,r,ans;
string a,b,c,d;
map<string,string>m;
bool z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		cin>>a>>b;
		m[a]=b;
	}
	for(int i=1;i<=q;i++){
		l=0;
		cin>>a>>b;
		len1=a.size();
		len2=b.size();
		if(len1!=len2){
			cout<<0<<endl;
			continue;
		}
		z=0;
		for(int j=0;j<len1;j++){
			if(a[j]!=b[j])r=j;
			if(!z&&a[j]!=b[j]){
				z=1;
				l=j;
			}
		}
		ans=0;
		for(int i=0;i<=l;i++){
			for(int j=r;j<len1;j++){
				c="";
				d="";
				for(int k=i;k<=j;k++){
					c+=a[k];
					d+=b[k];
				}
				if(m[c]==d)ans++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
