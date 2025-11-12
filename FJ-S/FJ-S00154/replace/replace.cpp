#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s[N],ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			if(s[i]==a&&ss[i]==b){
				ans++;
				break;
			}
		}
		
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<a.size();j++){
				string w=a.substr(i,j-i);
				for(int k=1;k<=n;k++){
					if(w==s[k]){
						string aa=a.substr(0,i);
						string bb=a.substr(j,a.size()-j);
						string ww=aa+ss[k]+bb;
						if(ww==b){
							ans++;
						}
					} 
				}
			}
		} 
		cout<<ans<<endl;
	} 
	return 0;
}

