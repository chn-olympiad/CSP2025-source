#include<bits/stdc++.h>
using namespace std;
struct abc{
	string s1,s2;
}a[200005],b[200005];
int n,q,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(long long z=1;z<=q;z++){
		cin>>b[z].s1>>b[z].s2;
		string s=b[z].s1,ss=b[z].s2,sss="",sss2="";
		for(long long i=1;i<=n;i++){
			if(s==a[i].s1&&ss==a[i].s2)ans=1;
		}
		for(long long i=0;s[i];i++){
			if(s[i]!=ss[i]){
				for(long long j=s.size()-1;j>=0;j--){
					if(s[j]!=ss[j]){
						for(long long k=i;k<=j;k++){
							sss+=s[k];
							sss2+=ss[k];
						}
						break;
					}
				}
				break;
			}
		}
		for(long long i=1;i<=n;i++){
			if(sss==a[i].s1&&sss2==a[i].s2)ans++;
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
} 
