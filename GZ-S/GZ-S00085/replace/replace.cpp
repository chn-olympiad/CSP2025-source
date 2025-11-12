//GZ-S00085 遵义市汇川区第三小学 吴昊然 
#include <bits/stdc++.h>
using namespace std;
struct aa{
	string x,y;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	aa s[n],t[q];
	for(int i=0;i<n;i++){
		cin>>s[i].x>>s[i].y;
	}
	for(int i=0;i<q;i++){
		cin>>t[i].x>>t[i].y;
		if((t[i].x).size()!=(t[i].y).size()){
			cout<<0;
		} else{
			int ans=0;
			string h=t[i].x;
			for(int j=0;j<t[i].x.size();j++){
				for(int z=0;z<n;z++){
					if(s[z].x[0]==t[i].x[j]&&s[z].y[0]==t[i].y[j]){
						bool f=1;
						for(int g=0;g<s[z].x.size();g++){
							if(s[z].x[g]!=t[i].x[j+g]||s[z].y[g]!=t[i].y[j+g]){
								f=0;
								break;
							}
						}
						if(f==1){
							for(int g=0;g<s[z].x.size();g++){
								h[g+j]=s[z].x[g];
							}
						}
					}
					if(h==t[i].y){
						ans++;
						h=t[i].x;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

