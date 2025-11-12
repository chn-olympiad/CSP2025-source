#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,cnt;
string s[200005],s1[200005];
string t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>t1>>t2;
		string t;
	    for(int j=1;j<=n;j++){
	    	t=t1;
	    	if(!((t.find(s[j])>=0)&&(t.find(s[j])<t.size())))continue;
	    	int f=t.find(s[j]);
	    	int l=s[j].size();
	    	for(int k=f;k<f+l;k++){
	    		t[k]=s1[j][k-f];
			}
			if(t==t2)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
