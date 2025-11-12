#include <bits/stdc++.h>
using namespace std;
int n,q,cnt;
struct node{
	string s1,s2;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for (int i=1;i<=q;i++){
		string t1,t2;
		cnt=0;
		cin>>t1>>t2;
		string y="",z="";
		for (int j=1;j<=n;j++){
			if (a[j].s1==t1 && a[j].s2==t2){
				cnt++;
			}
		}
		for (int j=0;j<=t1.size();j++){
			if (t1[j]!=t2[j]){
				y+=t1[j];z+=t2[j];
			}
		}
		for (int j=1;j<=n;j++){
			if (a[j].s1==y && a[j].s2==z){
				cnt++;
			}
		}
		cout<<cnt%998244353<<endl;
	}
	return 0;
}
