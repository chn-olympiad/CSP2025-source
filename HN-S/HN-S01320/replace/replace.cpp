#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int N=131;
const int M=1e5+5;
int n,q;
map<string,bool> mpb;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		mpb[s1]=true;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<0<<endl;
		int len=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int ans=0;
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len-j+1;k++){
				string str="",t0=t1;
				int l=k,r=k+j-1;
				for(int p=l;p<=r;p++){
					str+=t0[p];
				}
				if(mpb[str]){
					string res=mp[str];
					for(int p=l;p<=r;p++){
						t0[p]=res[p-l];
					}
					if(t0==t2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
