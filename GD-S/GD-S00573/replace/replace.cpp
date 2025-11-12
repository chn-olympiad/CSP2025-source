#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,q,cnt;
string s[400010];
map<string,vector<string>>mp;
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n*2;i+=2){
		string s1,s2;
		cin>>s1>>s2;
		s[i]=s1,s[i+1]=s2;
		mp[s1].push_back(s2);
		
	}
	for(ll i=1;i<=q;i++){
		string s1,s2;
		cnt=0;
		cin>>s1>>s2;
		for(int i=1;i<=n*2;i++){
			ll a=s1.find(s[i]);
			if(a<0)continue;
//			cout<<s[i]<<' '<<a<<'\n';
			for(auto c:mp[s[i]]){
//				cout<<"    "<<c<<'\n';
				string s3=s1;
				for(ll j=a;j<a+s[i].size();j++){
					s3[j]=c[j-a];
				}
//				cout<<"    "<<s3<<'\n';
				if(s3==s2){
					cnt++;
//					cout<<"    ++\n";
				}
			}
		}
//		cout<<'\n';
		
		cout<<cnt<<'\n';
//		cout<<"------------------------\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
