#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1,s2;
struct huan{
	string a,b;
	
}c[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
		cin>>c[i].a>>c[i].b;
	}
	while(q--){
		long long cnt=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<'0'<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;(long long)(j+c[i].a.size()-1)<(long long)s1.size();j++){
				int flag=1;
				for(int x=0;x<(long long)(c[i].a.size());x++){
					if(c[i].a[x]!=s1[x+j] || c[i].b[x]!=s2[x+j]){
						flag=0;
						break;
					}
				}
				if(flag){
					for(int x=0;x<j;x++)
						if(s1[x]!=s2[x]){
							flag=0;
							
							break;
						}
					if(!flag)break;
					for(int x=j+c[i].a.size();x<=(long long)s1.size();x++)
						if(s1[x]!=s2[x]){
							flag=0;
							break;
						}
				}
				if(flag)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
    
	return 0;
}
