#include<bits/stdc++.h>
using namespace std;
int n,m,i,w;
string x[200010],y[200010],s2,s1,s3,s4;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>x[i]>>y[i];
    while(m--){
    	cin>>s1>>s4;
    	int ans=0;
    	if(s1.size()!=s4.size()){
    		cout<<0<<"\n";
    		continue;
		}
    	for(i=1;i<=n;i++){
    	    s2=s1;
    		w=s2.find(x[i]);
    		while(w!=string::npos){
    			s3=s1;
    			s3.erase(w,x[i].size());
    			s3.insert(w,y[i]);
    			if(s3==s4){
    				ans++;
    				break;
				}
				s2.erase(w,x[i].size());
				w=s2.find(x[i]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

