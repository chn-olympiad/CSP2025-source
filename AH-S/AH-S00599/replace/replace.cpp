#include<bits/stdc++.h>
using namespace std;
pair<string,string> a[10004];
string s1,s2;
int n,q,c;
int work(){
	int ans=0;
	for(int st=0;st<s1.size();st++){
		for(int j=1;j<=n;j++){
			int f=1;
			int i=st,cnt=0;
			for(int k=0;k<a[j].first.size();k++,i++){
				if(s1[i]!=a[j].first[k]||s2[i]!=a[j].second[k]){
					f=0;
					break;
				}
				if(s1[i]!=s2[i])cnt++;
			}
			if(f&&cnt==c)ans++;
		}
	}
	return ans;			
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		cin>>s1>>s2;
		c=0;
		for(int i=0;s1[i];i++){
			if(s1[i]!=s2[i])c++;
		}
		cout<<work()<<"\n";
	}
	return 0;
}
