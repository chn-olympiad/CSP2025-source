#include <bits/stdc++.h>
using namespace std;
long long t,n,s,strl;
string str1,str2;
struct node{
	string s1,s2;
}a[200010];
bool cmp(node x,node y){
	if(x.s1.size()==y.s1.size()){
		if(x.s1==y.s1){
			return x.s2<y.s2;
		}
		return x.s1<y.s1;
	}
	return x.s1.size()<y.s1.size();
}
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	sort(a+1,a+n+1,cmp);
	while(t--){
		s=0;
		cin>>str1>>str2;
		strl=str1.size();
		for(int i=1;i<=n;i++){
			if(a[i].s1==a[i-1].s1){
				continue;
			}
			for(int k=0;k<=strl-a[i].s1.size();k++){
				s+=1;
				for(int j=0;j<a[i].s1.size();j++){
					if((str1[j+k]!=a[i].s1[j])||(str2[j+k]!=a[i].s2[j])){
						s-=1;
						break;
					}
				}
			}
		}
		cout<<s<<"\n";
	}
	return 0;
}
