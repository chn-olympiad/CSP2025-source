#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string s1[MAXN],s2[MAXN],t1[MAXN],t2[MAXN];
int f[5000001],ans[MAXN];
void kmp(string s){
	int j;
	for(int i=1;i<n;i++){
		j=f[i-1];
		while(j>0&&s[i]!=s[j]) j=f[j-1];
		if(s[i]==s[j]) j++;
		f[i]=j;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	bool flag=0;
	int k,o; 
	for(int i=1;i<=n;i++){
		kmp(s2[i]);
		for(int j=1;j<=q;j++){
			k=0,o=0;
			if(t1[j].size()!=t2[j].size()) continue ;
			while(k<=t2[j].size()){
//				printf("(%d,%d,%d,%d)",i,j,k,o);
				if(o==s2[i].size()){
					flag=1;
//					printf("**");
					for(int p=k-o;p<k;p++)
						if(s1[i][p-k+o]!=t1[j][p]){
//							printf("[%c,%c]",s1[i][p],t1[j][p]);
							flag=0;
							break;
						} 
					for(int p=0;p<k-o;p++)
						if(t1[j][p]!=t2[j][p]){
							flag=0;
							break;
						}
					for(int p=k;p<t1[j].size();p++)
						if(t1[j][p]!=t2[j][p]){
							flag=0;
							break; 
						} 
					if(flag) ans[j]++;
					o=0;
				}
				if(t2[j][k]==s2[i][o]) k++,o++;
				else k=k-f[o]+1,o=0;
			}
//			cout<<"\n";
		}
//		cout<<"\n";
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}