#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e6+10;
typedef long long ll;
int n,q,ans,b[26],pre[M];
string s1[N],s2[N],t1,t2;

void check(){
	for(int k=1;k<=n;k++){
		for(int i=0;i<=25;i++)
		for(int i=0;i<(int)s1[k].size();i++){
			if(b[s1[k][i]-'a']!=0)
				pre[i]=b[s1[k][i]-'a'];
			b[s1[k][i]-'a']=i;
		}
		int op=0;
		for(int i=0;i<(int)t1.size();i++){
			if(s1[k][op]==t1[i]){
				op++;
				if(op==(int)s1[k].size()){
					string s=t1;
					for(int t=0;t<(int)s1[k].size();t++){
						s[i-t]=s1[k][op-t];
					}
					if(s==t2)ans++;
					op=pre[op];
				}
			}
			
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<=25;i++)
		for(int i=0;i<(int)s2[k].size();i++){
			if(b[s2[k][i]-'a']!=0)
				pre[i]=b[s2[k][i]-'a'];
			b[s2[k][i]-'a']=i;
		}
		int op=0;
		for(int i=0;i<(int)t1.size();i++){
			if(s2[k][op]==t1[i]){
				op++;
				if(op==(int)s2[k].size()){
					string s=t1;
					for(int t=0;t<(int)s2[k].size();t++){
						s[i-t]=s2[k][op-t];
					}
					if(s==t2)ans++;
					op=pre[op];
				}
			}
			
		}
	}
}
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
	}	
	while(q--){
		cin>>t1>>t2;
		ans=0;
		check();
		cout<<ans<<endl;
	
	}
	
	return 0;
}
