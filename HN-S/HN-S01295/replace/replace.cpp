#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q;
string s1,s2,t1,t2,s3[N],s4[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s1>>s2;
    	int p=0,q=s1.length()-1;
    	for(;p<s1.length();p++){
    		if(s1[p]!=s2[p]){
    			break;
			}
		}
		for(;q>=0;q--){
			if(s1[q]!=s2[q]){
				break;
			}
		}
		for(int j=p;j<=q;j++){
			s3[i]+=s1[j];
			s4[i]+=s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		string t3,t4;
    	int p=0,q=t1.length()-1;
    	for(;p<t1.length();p++){
    		if(t1[p]!=t2[p]){
    			break;
			}
		}
		for(;q>=0;q--){
			if(t1[q]!=t2[q]){
				break;
			}
		}
		for(int j=p;j<=q;j++){
			t3+=t1[j];
			t4+=t2[j];
		}
		int ans=0;	
		for(int j=1;j<=n;j++){
			if(t3==s3[j]&&t4==s4[j]){
				ans++; 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
