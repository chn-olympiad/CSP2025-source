#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int bes=131;
int n,Q;
struct sp{
	string s1;
	string s2;
}a[100005];
inline void sol(){
	string t1,t2;
	cin>>t1>>t2;
	if(t1.size()!=t2.size()){
		cout<<0<<'\n';
		return ;
	}
	int sum=0;
	for(int i=0;i<t1.size();i++){
		for(int j=1;j<=n;j++){
			if(i+a[j].s1.size()-1<t1.size()){
				bool flag=1;
				for(int k=i;k<=i+a[j].s1.size()-1;k++){
					if(t1[k]!=a[j].s1[k-i]){
						flag=0;
					}
				}
				for(int k=i;k<=i+a[j].s1.size()-1;k++){
					if(t2[k]!=a[j].s2[k-i]){
						flag=0;
					}
				}
				for(int k=i+a[j].s1.size();k<t1.size();k++){
					if(t1[k]!=t2[k]){
						flag=0;
					}
				}
				if(flag){
					sum++;
				}
			}
		}
		if(t1[i]!=t2[i]){
			cout<<sum<<'\n';
			return ;
		}
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1 >>a[i].s2 ;
	}
	for(int i=1;i<=Q;i++){
		sol();
	}
	return 0;
}
