#include <bits/stdc++.h>
using namespace std;
const int N =2e5+10;
struct P{
	string s1,s2;
	
} a[N];
int n , q;
string t1,t2;
long long ans = 0 ;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i =1 ;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		string s1=a[i].s1,s2=a[i].s2;
		int l ,r;
		for(l=0;l<s1.size();l++){
			if(s1[l]!=s2[l])break;
			
		}
		for(r=s1.size();r>=0;r--){
			if(s1[r]!=s2[r])break;
		}
		if(l==s1.size()){
			i--;
			n--;
			continue;
		}
		a[i].s1=s1.substr(l,r-l+1);
		a[i].s2=s2.substr(l,r-l+1);
	}
	while(q--){
		ans = 0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l ,r;
		for(l=0;l<t1.size();l++){
			if(t1[l]!=t2[l])break;
			
		}
		for(r=t1.size();r>=0;r--){
			if(t1[r]!=t2[r])break;
		}
		t1=t1.substr(l,r-l+1);
		t2=t2.substr(l,r-l+1);
		for(int i =1;i<=n;i++){
			if(a[i].s1==t1 && a[i].s2==t2){
				ans++;
				
			}
		}
		cout<<ans<<'\n';
		
	}
}
