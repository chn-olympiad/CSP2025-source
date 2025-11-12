#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int quan[200005];
bool include(string s1,string s2,string t1,string t2){
	if(s1.size()!=s2.size()||t1.size()!=t2.size()||t1.size()<s1.size()){
		return 0;
	}
	int lens=s1.size(),lent=t1.size();
	int x=0;
	int f=0;
	int l,r;
	for(int i=0;i<=lent-lens;i++){
		while(x<lens&&t1[i+x]==s1[x]&&t2[i+x]==s2[x]){
			x++;
		}
		if(x==lens){
			f=1;
			l=i;
			r=l+lens;
			break;
		}else{
			x=0;
		}
	}
	if(f){
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){
				return 0;
			}
		}
		for(int i=r;i<lent;i++){
			if(t1[i]!=t2[i]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int x=0;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	/*for(int i=0;i<n;i++){
		cout<<s[i][0]<<" "<<s[i][1]<<endl;
	}*/
	for(int i=0;i<q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int j=0;j<n;j++){
			if(include(s[j][0],s[j][1],t1,t2)){
				ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 