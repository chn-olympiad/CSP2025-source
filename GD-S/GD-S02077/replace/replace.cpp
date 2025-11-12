#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct Str{
	string s1;
	string s2;
	int len;
};
vector<Str> str;
string shu1,shu2;
bool cmp(const Str &x, const Str &y){
	if(x.len!=y.len){
		if(x.s1==y.s1){
			return x.s2<y.s2;
		}
		return x.s1<y.s1;
	}
	return  x.len<y.len; 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>shu1>>shu2;
		str.push_back({shu1,shu2,shu1.size()});
	}
	sort(str.begin(),str.end(),cmp);
	for(;q--;){
		ans=0;
		cin>>shu1>>shu2; 
		if(shu1.size()!=shu2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=shu1.size()-1;
		while(shu1[l]==shu2[l]){
			l++;
		}
		while(shu1[r]==shu2[r]){
			r--;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j+str[i].len-1<shu1.size();j++){
				if(j>l || j+str[i].len-1<r)
					continue;
				bool zh=true;
				for(int l=0;l<str[i].len;l++){
					if(str[i].s1[l]!=shu1[l+j]){
						zh=false;
						break;
					}
					if(str[i].s2[l]!=shu2[l+j]){
						zh=false;
						break;
					}
				} 
				if(zh){
					ans++;
//					cout<<i<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
}
