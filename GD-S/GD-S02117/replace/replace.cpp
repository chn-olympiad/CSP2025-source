#include<bits/stdc++.h>
using namespace std;
string t1[200010];
string t2[200010];
int n,q;
int bh(string str1,string str2){
	int l1=str1.size();
	int l2=str2.size();
	for(int i=0;i<=l2-l1;i++){
		bool flag=true;
		for(int k=0;k<l1;k++){
			if(str2[i+k]!=str1[k]){
				flag=false;
				break;
			}
		}
		if(flag)return i;
	}
	return -1;
}
int main(){
	freopen("r","replace.in",stdin);
	freopen("w","replace.out",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>t1[i]>>t2[i];
	for(int p=1;p<=q;p++){
		string s1,s2;
		cin>>s1>>s2;
		int l=s1.size();
		int begin_=l-1,end_=0;
		for(int i=0;i<l;i++)
			if(s1[i]!=s2[i]){
				begin_=i;
				break;
			}
		for(int i=l-1;i>=0;i--)
			if(s1[i]!=s2[i]){
				end_=i;
				break;
			}
		string zj1,zj2;
		for(int i=begin_;i<=end_;i++)zj1+=s1[i];
		for(int i=begin_;i<=end_;i++)zj2+=s2[i];
//		cout<<"\npppp\n"<<zj1<<" m "<<zj2<<"  ppp"<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a1_p=bh(zj1,t1[i]);
			int a2_p=bh(zj2,t2[i]);
			if(a1_p==a2_p&&a1_p!=-1)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
