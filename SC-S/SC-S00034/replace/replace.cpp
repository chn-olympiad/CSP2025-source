#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[2][N],s1,s2;
int n;
int find(int le,string str1,string str2,int x){
	for(int j=x;j<=n;j++){
		if(s[0][j].size()==le){
			if(s[0][j]==str1 && s[1][j]==str2) return j;
    	}
	}return 0;
}
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	int Q;cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i];
	while(Q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) cout<<0<<"\n";
		else{
			int ans=0;
			for(int i=0;i<(int)s1.size();i++){
				if(i!=0){
					if(s1[i-1]!=s2[i-1]) continue;
				}
				for(int j=(int) s1.size()-1;j>=i;j--){
					if(j!=(int) s1.size()-1){
						if(s1[j+1]!=s2[j+1]) continue;
					}int y=1;
					string temp="";string tp="";
					for(int k=i;k<=j;k++) temp+=s1[k];
					for(int o=i;o<=j;o++) tp+=s2[o];
					y=find(j-i+1,temp,tp,y);
					if(y){
						ans++;
						while(y>0 && y<=n){
							y=find(j-i+1,temp,tp,y);
						}
					}
				}
			}cout<<ans<<"\n";
		}
	}return 0;
}