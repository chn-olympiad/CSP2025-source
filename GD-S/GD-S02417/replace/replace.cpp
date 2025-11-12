#include<bits/stdc++.h>
using namespace std;
string a[200005][2],t1,t2;
int n,p,i,j,sum,s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	for(i=0;i<p;i++){
		sum=0;
		cin>>t1>>t2;
		for(j=0;j<n;j++){
			s1=t1.find(a[j][0]);
			s2=t2.find(a[j][1]);
			if(s1!=-1&&s2!=-1&&s1==s2){
				if(t1.substr(0,s1)==t2.substr(0,s2)&&t1.substr(s1+a[j][0].size(),t1.size())==t2.substr(s2+a[j][1].size(),t2.size())) sum++;
			}
		}
		cout<<sum<<'\n'; 
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
2
0
*/
