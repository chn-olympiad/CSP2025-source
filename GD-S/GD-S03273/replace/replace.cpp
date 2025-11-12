#include<bits/stdc++.h>
using namespace std;
int qb1[200086],qb2[200086],si[200086];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q,flag = 1;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		string s,s1;
		cin>>s>>s1;
		si[i] = s.size();
		for(int j = 0;j<=s.size();j++){
			if(s[j]=='b'){
				qb1[i] = j;
				break;
			}
			if(s[j]!='a'&&s[j]!='b')
				flag = 0;
		}
		for(int j = 0;j<=s.size();j++){
			if(s1[j]=='b'){
				qb2[i] = j;
				break;
			}
			if(s1[j]!='a'&&s1[j]!='b')
				flag = 0;
		}
	}
		
	while(q--){
		string t,t1;
		int b1,b2,ans = 0;
		cin>>t>>t1;
		if(!flag){
			printf("0\n");
			continue;
		}
		for(int i = 0;i<=t.size();i++){
			if(t[i]=='b'){
				b1 = i;
				break;
			}
		}
		for(int i = 0;i<=t1.size();i++){
			if(t1[i]=='b'){
				b2 = i;
				break;
			}
		}
		for(int i = 1;i<=n;i++)
			if(si[i]<=t.size()&&qb2[i]<=b2)
				if(qb2[i]-qb1[i]==b2-b1||qb2[i]<b2-b1)
					ans++; 
		printf("%d\n",ans);			
	}
	return 0;
}
