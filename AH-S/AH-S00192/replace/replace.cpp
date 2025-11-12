#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int n,q,ans,c;
string s,w,h[200005];
map<string,string> g;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>w;
		g[s]=w;
		h[i]=s;
	}
	while(q--){
		ans=0;
		c=0;
		cin>>s>>w;
		//cout<<s.find("aa",3)<<endl;
		for(int i=1;i<=n;){
			if(s.find(h[i],c)<s.size()&&0<=s.find(h[i],c)){
				int pos=s.find(h[i],c);
				c=pos+h[i].size();
				//cout<<pos<<" "<<c<<endl;
				string tmp1,tmp2,tmp3;
				tmp1=s.substr(0,pos);
				tmp3=s.substr(pos+h[i].size(),s.size()-pos-h[i].size()+1);
				tmp2=g[h[i]];
				string f=tmp1+tmp2+tmp3;
				//cout<<f<<" "<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
				if(f==w){
					ans++;
				}
			}else{
                i++;
			}
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
