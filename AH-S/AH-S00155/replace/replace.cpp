#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,ci,ans[N];
map<string,string> s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str1,str2;
		cin>>str1>>str2;
		s[str1]=str2;
	}
	while(q--){
		string init,goal;
		cin>>init>>goal;
		int len1=init.length(),cnt=0;
		for(int i=0;i<len1;i++){
			for(int j=i;j<len1;j++){
				string str="";
				for(int k=i;k<=j;k++) str+=init[k];
				if(s.find(str)!=s.end()){
					string check="";
					for(int k=0;k<i;k++) check+=init[k];
					check+=s[str];
					for(int k=j+1;k<len1;k++) check+=init[k];
					if(check==goal) cnt++;
				}
			}
		}
		ans[++ci]=cnt;
	}
	for(int i=1;i<=ci;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
