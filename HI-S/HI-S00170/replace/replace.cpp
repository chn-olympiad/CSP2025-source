#include<bits/stdc++.h>
using namespace std;
struct stri{
	string s1,s2;
}s[200010];
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}while(q--){
		string t1,t2;cin>>t1>>t2;long long sum=0;
		for(long long i=0;i<n;i++){
			if(t1.find(s[i].s1)!=-1){
				string t3="",t4="";
				for(long long j=0;j<t1.find(s[i].s1);j++){
					t3+=t1[j];
				}for(long long j=t1.find(s[i].s1)+s[i].s1.size();j<t1.size();j++){
					t4+=t1[j];
				}if(t3+s[i].s2+t4==t2)sum++;
			}
		}
		cout<<sum;
	}
 return 0;
}

