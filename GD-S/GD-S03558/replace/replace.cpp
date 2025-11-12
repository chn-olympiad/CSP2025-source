#include<bits/stdc++.h>
using namespace std;
struct sg{
	string h,t;
};
sg a[200050];
int n,q,ans;
int main(){
	string s1,s2,s3="",s4="";
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>a[i].h>>a[i].t;
	}
	while(q--){
		cin>>s1>>s2;
		for(int i = 0;i < s1.size();i++){
			if(s1[i] != s2[i]){
				s3 += s1[i];
				s4 += s2[i];
			}
		}
		for(int i = 1;i <= n;i++){
			if(s3 == a[i].h && s4 == a[i].t){
				ans++;
			}
		}
		for(int i = 1;i <= n;i++){
			if(s1 == a[i].h && s2 == a[i].t){
				ans++;
			}
		}
		cout<<ans<<"\n";
		ans = 0;
		s3 = "";
		s4 = "";
	}
	return 0;
}
