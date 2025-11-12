#include<bits/stdc++.h>
#define N 200086
#define ll long long
using namespace std;
int n,q,ans;
int vised[28][N];
string s[N][3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		vised[s[i][1][0]-'a'+1][0]++;
		vised[s[i][1][0]-'a'+1][vised[s[i][1][0]-'a'+1][0]]=i;
	}
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		string stemp;
		for(int i=0;i<t1.size();i++){
			if(vised[t1[i]-'a'+1][0]){
				for(int j=1;j<=vised[t1[i]-'a'+1][0];j++){
					if(t1.size()-i>=s[vised[t1[i]-'a'+1][j]][1].size()){
						int f=0;
						for(int k=0;k<s[vised[t1[i]-'a'+1][j]][1].size();k++){
							if(t1[k+i]!=s[vised[t1[i]-'a'+1][j]][1][k]){
								f=1;
								break;
							}
						}
						if(!f){
							string etemp;
							for(int k=i+s[vised[t1[i]-'a'+1][j]][1].size();k<t1.size();k++) etemp.push_back(t1[k]);
							string new_t1=stemp+s[vised[t1[i]-'a'+1][j]][2]+etemp;
							if(new_t1==t2) ans++;
						}
					}
				}
			}
			stemp.push_back(t1[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
I love you,ccf
please give me more FenShu
*/
