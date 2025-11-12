#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,q;long long tmp;
string s1[200005],s2[200005],x,y,z,w;
int main(){
	freopen("replaxe.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
	    cin>>s1[i]>>s2[i];
	}
	while(q--){
	    cin>>x>>y;
	    z=x;
	    for(int i=0;i<n;i++){
			for(int j=0;j+s1[i].size()<x.size();j++){
				w=x.substr(j,j+s1[i].size());
				bool f=1;
				int cc=0;
				for(auto k=s1[i].begin();k!=s1[i].end();k++){
					if(w[cc]!=*k){
						f=0;break;
					}cc++;
				}
				cc=0;
				if(f){
					for(auto k=s2[i].begin();k!=s2[i].end();k++){
						x[cc]=*k;
					cc++;
				    }
					if(x==y) tmp++;
					x=z;
				}
			}
		}
		cout<<tmp;
    }
}
