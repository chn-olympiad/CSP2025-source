#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
pair<string,string> a[maxn];
pair<string,string> ss[maxn];
//how 2G memory limit?
//I've write this rubbish for 15min for only 10 pts
//oh and even sum of my score is less then 50
//I'm totally rubbish
//I've done so much for CSP
//Yesterday I've got passed 19 moban
//difficulty from green to blue
//but why does it didn't even work?!!
//I don't think I'm that bad
//It's really frustrating
//And I'm in the second year in secondary school in HF!
//It's too late next year!
//I really like OI and I think I have abit talent in it
//but it turns out to be only a hallucination
bool special(string s){
	map<char,int>mp;
	int cnt=0;
	string ss;
	for(int i=0;i<s.size();i++){
		if(!mp[s[i]]++){
			cnt++;
			if(cnt==3)return false;
			ss=ss+s[i];
		}
	}
	int k=mp[ss[1]],kk=mp[ss[0]];
	return ((k==1)||(kk==1));
}
bool B=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
//		B&=special(a[i].first);B&=special(a[i].second);
	}
	for(int i=1;i<=q;i++){
		cin>>ss[i].first>>ss[i].second;
//		B&=special(ss[i].first);B&=special(ss[i].second);
	}
//	if(B){
		//What happens if B?How do I know?
//	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string s1=ss[i].first,s2=ss[i].second;
		int l1=s1.size();//KMP?It doesn't seems to work on this one
		for(int i=1;i<=n;i++){
			string t1=a[i].first,t2=a[i].second;
//			cout<<t1<<' '<<t2<<endl;
			for(int j=0;j<l1;j++){
				bool t=1,s=1;
				for(int k=0;k<t1.size()&&j+k<l1;k++){
					t&=(s1[j+k]==t1[k]);
					if(!t)break;
				}
				if(t){
					for(int k=0;k<t2.size()&&j+k<l1;k++){
						s&=(s2[j+k]==t2[k]);
						if(!s)break;
					}
//					cout<<t<<' '<<s<<endl;
					if(s){
						string s3=s1;
//						cout<<s3<<endl;
						for(int k=0;k<t1.size()&&j+k<l1;k++){
							s3[j+k]=t2[k];
						}
//						cout<<s3<<endl;
						if(s3==s2)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
