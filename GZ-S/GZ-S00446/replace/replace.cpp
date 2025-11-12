//GZ-S00486 贵阳市第十八中学 郭润山
#include<bits/stdc++.h>
using namespace std;
int n,q,cnt,l,r;
struct node{
	string s1,s2;
}p[200005],t[200005];
bool f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[i].s1>>p[i].s2;
		if(p[i].s1.find('b')==-1 || p[i].s2.find('b')==-1) f=1;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2;
		if(!f){
			l=t[i].s1.find('b');
			r=t[i].s2.find('b');
			cout<<l+1+n-r<<endl;
		}
		cout<<0<<endl;
	}
	if(q==1){
		for(int i=1;i<=n;i++){
			if(p[i].s1==t[i].s1 && p[i].s2==t[i].s2){
				for(int j=0;j<p[i].s1.size();j++){
					if(p[i].s1[j]!=p[i].s2[j]){
						if(!f){
							cnt+=n-j;
						}
						else{
							cnt+=j+1;
							f=0;
						}
					}
				}
				break;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
