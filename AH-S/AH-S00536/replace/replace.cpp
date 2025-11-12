#include <bits/stdc++.h>
using namespace std;
int n,q,k,ans;
struct replace{
	string a,b;
}r[200003];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>r[i].a>>r[i].b;
	}
	while(q--){
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			bool flag1=0,flag2=1;
			//k=s1.find(r[i].a);
			for(int x=0,y=0;x<s1.size(),y<s2.size();x++,y++){
				if(s1[x]!=s2[y]&&!flag1){
					 flag1=1;
					 bool temp=0;
					 string xx=(r[i].a);
					 for(int j=0;j<xx.size();j++){
						 if(s1[x+j]!=r[i].a[j]){
							temp=1;
						 }
					 }
					 if(!temp){
						 string yy=(r[i].b);
						for(int j=0;j<yy.size();j++){
							if(s2[y+j]!=r[i].b[j]){
								temp=1;
							}
						}
						if(temp){
							flag2=0;
						}
					 }
				}
			}
			if(flag2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}																																																																																																																																																																																																																										
