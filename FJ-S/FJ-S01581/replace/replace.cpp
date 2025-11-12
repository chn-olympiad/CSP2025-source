#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string ss1,ss2;
};
vector<node> s;
bool pd(int l,int r,string ss,string ssss){
	if(r-l+1>ss.size())return 0;
	string sss="";
	for(int i=l;i<=r;i++){
		sss=sss+ssss[i];
	}
	if(sss==ss)return 1;
	//cout<<ss<<endl;
	//ss可能比sss长!!!!!!!!!!!!!!!!!!!!!!!!!
	bool f=1;
	int ll,rr;
	for(int i=0;i<ss.size();i++){
		string s3="";
		for(int j=i;j<i+sss.size();j++){
			s3=s3+ss[j];
		}
		if(s3==sss){
			ll=i;
			rr=i+s3.size()-1;
			f=0;
			break;
		}
	}
	if(f)return 0;
	//cout<<ss<<endl;
	//cout<<ll<<" "<<rr<<endl;
	//ss[0-ll]=s<<sss[(l-1+ll)-(l-1)] 
	string sss1="",sss2="";
	for(int i=0;i<ll;i++)sss1=sss1+ss[i];
	for(int i=rr;i<ll;i++)sss2=sss2+ssss[i];
	if(sss1!=sss2)return 0;
	
	//cout<<ss<<endl;
	//ss[rr-(ss.size()-1)]=ssss[(r+1)-(r+1-rr+(ss.size()-1))]
	for(int i=rr;i<(ss.size()-1);i++)sss1=sss1+ss[i];
	for(int i=(r+1);i<(r+1-rr+(ss.size()-1));i++)sss2=sss2+ssss[i];
	if(sss1!=sss2)return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//cout<<n<<" "<<q<<endl;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s.push_back({s1,s2});
	}
	//cout<<"----------\n";
	while(q--){
		string s1,s2;
		int ans=0;
		int l=0,r=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=s1.size();i++){
			if(s1[i]!=s2[i]){
				if(l)r=i;
				else l=i;
			}
		}
		//cout<<l<<" "<<r<<endl;
		for(int i=0;i<s.size();i++){
			if(pd(l,r,s[i].ss1,s1)&&pd(l,r,s[i].ss2,s2)){
				ans++;
			}
		}
		cout<<ans<<endl/*<<"-------------\n"*/;
	}
	return 0;
} 
