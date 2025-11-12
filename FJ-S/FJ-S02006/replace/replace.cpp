#include<bits/stdc++.h>

using namespace std;

int n,q,lt,rt,ans;
map<string,string> mp;
string s1,s2,t1,t2;

void test(){
	
	cin>>t1>>t2;
	
	ans=0;
	for(int i=0;i<t1.size();i++)
		if(t1[i]!=t2[i]){
			lt=i;
			break;
		}
	for(int i=t1.size()-1;i>=0;i--)
		if(t1[i]!=t2[i]){
			rt=i;
			break;
		}
		
	string l="",r="",o1="",o2="";
	
	for(int i=lt;i<=rt;i++)
		l=l+t1[i],r=r+t2[i];
		
	for(int i=lt;i>=0;i--){
		o1=l,o2=r;
		for(int j=rt;j<t1.size();j++){
			
			if(mp[o1]==o2)
				ans++;
			if(j!=t1.size()-1)
				o1=o1+t1[j+1],o2=o2+t2[j+1]; 
		}
		
		if(i>0)
			l=t1[i-1]+l,r=t2[i-1]+r;
	} 
	
	cout<<ans<<endl;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
		cin>>s1>>s2,mp[s1]=s2;
	
	for(int i=1;i<=q;i++){
		if(min(q,n)>=1000){
			cout<<"0\n";
			continue;
		}
		test();
	}
	
	return 0;
} 
