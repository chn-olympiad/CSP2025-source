#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][3];
string t,tt;
string tmp;
int sl(){
	int x,z,xx,zz;
	int ans=0;
	for(int i=0;i<t.size();i++){
		if(t[i]=='b'){
			x=i;
			z=t.size()-1-i;
			break;
		}
	}
	for(int i=0;i<tt.size();i++){
		if(tt[i]=='b'){
			xx=i;
			zz=tt.size()-1-i;
			break;
		}
	}
	int v=xx-x;
	int vv=zz-z;
	int tpx;
	int tpz;
	for(int i=1;i<=n;i++){
		for(int i=0;i<s[i][1].size();i++){
			int v=s[i][1].size()-i-1;
			if(s[i][1][i]=='b'){
				for(int ii=0;ii<s[i][2].size();ii++){
					if(s[i][2][ii]=='b'){
						if(ii-i==v&&(s[i][2].size()-ii-1-v)==zz){
							ans++;
						}	
						break;
					}
				}
			}
		}
	}
	
	return ans;
}
int sll(){
	
}
bool fl;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(!fl){
			for(auto v:s[i][1]){
				if(v!='a'&&v!='b'){
					fl=1;
					break;
				}
			}for(auto v:s[i][1]){
				if(v!='a'&&v!='b'){
					fl=1;
					break;
				}
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		cin>>t>>tt;
		cout<<sl()<<'\n';
	}//Ã»Ê±¼äÀ± 
	return 0;
}

