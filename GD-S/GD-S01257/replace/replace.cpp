#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
void chack(string t,string t1,string s,string s1){
//	cout<<"t: "<<t<<" "<<t1<<endl;
//	cout<<"s: "<<s<<" "<<s1<<endl;
	for(int i=0;i<t.size();i++){
		for(int j=0;j<=s.size();j++){
			if(j==s.size()){
				for(int k=i;k<i+j;k++){
					t[k]=s1[k-i];
				}
				if(t==t1)ans++;
				return;
			}
			if(t[i+j]!=s[j]){
				break;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	string s[2000];
	string s1[2000];
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	string t,t1;
	for(int i=1;i<=q;i++){
		cin>>t>>t1;
		ans=0;
		for(int j=1;j<=n;j++){
			chack(t,t1,s[j],s1[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

