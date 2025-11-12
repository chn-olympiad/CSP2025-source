#include<bits/stdc++.h>
using namespace std;
struct ss{
	string a;
	string b;
}ss[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string t1,t2;
	for(int i=0;i<n;i++){
		cin>>ss[i].a>>ss[i].b;
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<ans;
			break;
		}
		for(int i=0;i<n;i++){
			if(t1.find(ss[i].a)==t2.find(ss[i].b)){
			    bool r=1;
			    for(int j=0;j<t1.find(ss[i].a);j++){
			        if(t1[j]!=t2[j]){
			            r=0;
			        	break;
					}}
				for(int j=t1.find(ss[i].a)+ss[i].a.size();j<t1.size();j++){
			        if(t1[j]!=t2[j]){
			        	r=0;
			        	break;
					}}
				if(r) ans++;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
