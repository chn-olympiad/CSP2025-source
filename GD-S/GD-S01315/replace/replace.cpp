#include<bits/stdc++.h>
using namespace std;
int f(string s1,string s2,string t1,string t2){
	int res=0;
	for(int i=0;i+t1.size()<s1.size();i++){
		bool f=true;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=s1[i+j]){
				f=false;
				break;
			}
		}
		if(f){
			bool flag=true;
			for(int j=0;j<i;i++){
				if(s2[j]!=s1[j]){
					flag=false;
					break;
				}
			}
			for(int j=i;j<i+t1.size();i++){
				if(s2[j]!=t2[j-i]){
					flag=false;
					break;
				}
			}
			for(int j=i+t1.size();j<s1.size();i++){
				if(s2[j]!=s1[j]){
					flag=false;
					break;
				}
			}
			if(f)res++;
		}
	}
	return res;
}
string s1[100005],s2[100005];
string t1[100005],t2[100005];
int n,q;
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int sp1[100005],sp2[100005];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b')sp1[i]=j;
			if(s2[i][j]=='b')sp2[i]=j;
		}
	}
	if(n<=100){
		for(int i=1;i<=q;i++){
			cin>>t1[i]>>t2[i];
			for(int j=1;j<=n;j++){
				ans+=f(t1[i],t2[i],s1[i],s2[i]);
			}
			cout<<ans<<'\n';
		}
	}else{
		for(int i=1;i<=q;i++){
			cin>>t1[i]>>t2[i];
			int p1,p2;
			for(int j=0;j<t1[i].size();j++){
				if(t1[i][j]=='b')p1=j;
				if(t1[i][j]=='b')p2=j;
			}
			for(int j=1;j<=n;j++){
				if(s2[i].size()-1-sp2[j]+p2<t2[i].size()&&p2-sp2[j]==p1)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
