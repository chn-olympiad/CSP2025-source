#include<bits/stdc++.h>
using namespace std;
int n,q,f,h;
string s[(int)2e5+5][2],a,b,xa,xb,ya,yb,za,zb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>a>>b;
		if(a.length()!=b.length()){
			cout<<0<<endl;
			continue;
		}
		h=0;
		for(int i=0;i<=a.length();i++){
			for(int j=i;j<=a.length();j++){
				xa="",xb="",ya="",yb="",za="",zb="";
				for(int k=0;k<i;k++){
					xa+=a[k];
					xb+=b[k];
				}
				if(xa!=xb)continue;
				for(int k=j;k<a.length();k++){
					za+=a[k];
					zb+=b[k];
				}
				if(za!=zb)continue;
				for(int k=i;k<j;k++){
					ya+=a[k];
					yb+=b[k];
				}
				f=1;
				for(int i=0;i<n;i++){
					if(ya==s[i][0]&&yb==s[i][1])f=0;
				}
				if(f)continue;
				h++;
			}
		}
		cout<<h<<endl;
	}
}
