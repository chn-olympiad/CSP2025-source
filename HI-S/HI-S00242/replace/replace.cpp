#include<bits/stdc++.h>
using namespace std;
int n,q,len,ans;
string t1,t2;
struct node{
	string s1,s2;
}a[200005];
bool pd(string t1,string t2,string s1,string s2){
	int f1=t1.find(s1),f2=t2.find(s2);
	for(int i=f1;i<f1+s2.size();++i){
		t1[i]=s2[i-f1];
	}
//	cout<<t1<<" "<<t2<<" "<<s1<<" "<<s2<<" "<<f1<<" "<<f2<<"\n";
	if(t1==t2){
		return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;++i){
		ans=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;++j){
			if(pd(t1,t2,a[j].s1,a[j].s2)){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
