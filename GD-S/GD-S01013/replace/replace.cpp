#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
string s1[N],s2[N];
int n,q,ans;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1,x;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		for(int j=1;j<=n;j++)
			if(s1[j].length()<=t1.length()){
				x=t1.find(s1[j]);
//				cout<<s1[j]<<" "<<x<<'\n';
				if(x!=-1){
					string xx="",zz="";
					xx=t1.substr(0,x);
					if(t1.length()-x+s2[j].length()>0)
						zz=t1.substr(x+s2[j].length(),t1.length()-x+s2[j].length());
//					cout<<"xx:"<<xx<<"\nyy:"<<zz<<'\n';
					if(xx+s2[j]+zz==t2)
						ans++;
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
