#include<bits/stdc++.h>
using namespace std;
struct init{
	string p;
	string n;
};
init a[1000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].p>>a[i].n;
	}
	while(q--){
		int ans=0;
		string t,t2;
		cin>>t>>t2;
		int w=t.size();
		for(int i=0;i<w;i++){
			for(int j=i;j<w;j++){
				string s;
				for(int k=i;k<=j;k++){
					s+=t[k];
				}
				for(int k=1;k<=n;k++){
					if(s==a[k].p){
						string ps,ns;
						for(int m=0;m<i;m++){
							ps+=t[m];
						}
						for(int m=j+1;m<w;m++){
							ns+=t[m];
						}
						string sans=ps+a[k].n +ns;
						if(sans==t2){
							ans++;
						} 
					} 
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
	/*4 2
	xabcx xadex
	ab cd
	bc de
	aa bb
	xabcx xadex
	aaaa bbbb
	*/
}
