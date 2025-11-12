#include<iostream>
#include<cstdio>
#include<map>
#include<unordered_map>

using namespace std;

const int M=1e5+5;

unordered_map<string,int> mp;

string s[M];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		string a;
		cin>>a>>s[i];
		mp[a]=i;
	}
	
	while(m--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		
		string x="";
		for(int i=0;i<a.size();i++){
			string z="";
			for(int j=a.size()-1;j>=0;j--){
				string y="";
				for(int k=i;k<=j;k++){
					y+=a[k];
				}
				if(mp.find(y)!=0){
					y=s[mp[y]];
				}
				string tmp;
				tmp=x+y+z;
				if(tmp==b){
					ans++;
				}
				z=a[j]+z;
			}
			x=x+a[i];
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
