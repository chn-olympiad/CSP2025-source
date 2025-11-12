#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,L=2005;
char s1[N][L],s2[N][L];
int l[N],pi[L],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=strlen(s1[i]);
	}
	for(int i=1;i<=m;i++){
		string ss1,ss2;
		cin>>ss1>>ss2;
		int len=ss1.length();
		int h=0,t=len-1;
		while(h<len&&ss1[h]==ss2[h])h++;
		while(t>=0&&ss1[t]==ss2[t])t--;
		for(int ii=1;ii<=n;ii++){
			string s=s1[ii]+'#'+ss1;
			int ll=s.length();
			int k=1;
			for(int j=0;j<ll;j++){
				while(k!=0&&s[j]!=s[k])
					k=pi[k-1];
				if(s[j]==s[k])k++;
				pi[j]=k;
				if(pi[j]==l[ii]){
					int NOW=i-2*l[ii];
					int now=NOW;
					if(now>h)break;
					while(now-NOW<=l[ii]&&ss2[now]==s2[ii][now])now++;
					if(now-NOW==l[ii]&&now>=t)ans++;
				}
			}
		}
		
	}
	
	return 0;
} 
