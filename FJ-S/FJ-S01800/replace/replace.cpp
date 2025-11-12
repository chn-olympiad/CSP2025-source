#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,q;
int len[N],pi1[N][N],pi2[N][N],f[N],fi[N];
string s1[N],s2[N];
string t1,t2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int k=1;k<=n;k++){
		cin>>s1[k]>>s2[k];
		len[k]=s1[k].size(),s1[k]=" "+s1[k],s2[k]=" "+s2[k];
		pi1[k][0]=0;
		for(int i=2;i<=len[k];i++){
			int j=pi1[k][i-1];
			while(j>0&&s1[k][i]!=s1[k][j+1])
				j=pi1[k][j];
			if(s1[k][i]==s1[k][j+1])
				j++;
			pi1[k][i]=j; 
		} 
		pi2[k][0]=0;
		for(int i=2;i<=len[k];i++){
			int j=pi2[k][i-1];
			while(j>0&&s2[i]!=s2[j+1])
				j=pi2[k][j];
			if(s1[i]==s2[j+1])
				j++;
			pi2[k][i]=j; 
		} 		
	}
	while(q--){
		cin>>t1>>t2;
		int len_=t1.size(),tl=t2.size(),ans=0;
		t1=" "+t1,t2=" "+t2;
		int l=-1,r=-1;
		if(len_!=tl){
			cout<<0<<'\n';
			continue;
		} 
		for(int i=1;i<=len_;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
				
		}
		for(int i=len_;i>=1;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}	
		} 
		for(int k=1;k<=n;k++){
			int tmp=0;
			for(int i=0;i<=len[k];i++)
				f[0]=0; 
			for(int i=1;i<=len_;i++){
				int j=f[i-1];
				while(j>0&&(j==len_||t1[i]!=s1[k][j+1]))
					j=pi1[k][j];
				if(t1[i]==s1[k][j+1])
					j++;
				f[i]=j;
				if(j==len[k])
					tmp=i;
			}	
			f[0]=0;
			for(int i=1;i<=len_;i++){
				int j=f[i-1];
				while(j>0&&(j==len_||t2[i]!=s2[k][j+1]))
					j=pi2[k][j];
				if(t2[i]==s2[k][j+1])
					j++;
				f[i]=j;
				if(j==len[k]&&tmp&&(i>=r&&i-len[k]+1<=l)){
					ans++;
					//cout<<i<<' '<<s1[k]<<' '<<s2[k]<<'\n'; 
				}
			}			
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}

