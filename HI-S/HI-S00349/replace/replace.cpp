#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
	string s1,s2;
	int len;
}li[N*2];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		cin>>li[i].s1>>li[i].s2;
		string s=li[i].s1;
		li[i].len=s.size();
	}
	for(int i=1;i<=q;++i){
		int ans=0;
		string s1,s2,s;
		cin>>s1>>s2;
		for(int j=1;j<=n;++j){
			s=s1;
			int len=li[j].len;
			string str1=li[j].s1;
			string str2=li[j].s2;
			for(int k=0;k<s.size();k+=len){
				string str=s.substr(k,len);
				//cout<<str<<" ";
				if(str==str1){
					s.erase(k,len);
					s.insert(k,str2);
					if(s==s2){
						ans++;
						break;
					}
					else s=s1;
				}
			}
			//cout<<endl;
		}
		//cout<<endl;
		printf("%d\n",ans);
	}
return 0;
}

