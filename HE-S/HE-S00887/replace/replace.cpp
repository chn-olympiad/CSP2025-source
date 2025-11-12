#include<bits/stdc++.h>
using namespace std;
int q,n;
string a[500100],b[500100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
   	cin>>n>>q;                                                  
    for(int i=1;i<=n;i++){
   cin>>a[i]>>b[i];
	}
	while(q--){
		long long ans=0;
	string s1,s2;	
	cin>>s1>>s2;
    for(int i=1;i<=n;i++)
    {     int k=s1.find(a[i]);
    	if(k!=-1){
    	string p=s1;
			p.replace(k,a[i].size(),b[i]);
		if(p.size()==s2.size()&&p==s2) ans++;	
		}
	}
		cout<<ans<<'\n';  	
	}
		                                                  
	return 0;
}
