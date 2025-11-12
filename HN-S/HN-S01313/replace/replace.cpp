#include<bits/stdc++.h>
using namespace std;

struct TFTS{
	string s1,s2;
};

int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		string s,s_to,tmp,s1,s2;
		cin>>s>>s_to;
		tmp=s;
		int len=0,res=0;
		for(int j=1;j<=n;j++){
			cin>>s1>>s2;
			if(s.find(s1)!=-1){
				tmp.replace(s.find(s1),s1.size(),s2);
			}
			if(tmp==s_to) res++;
		}
		cout<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

