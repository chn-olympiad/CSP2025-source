#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+10,M=5e6+10;
int n,m,ne[N][N];
string s[N][5],q[N][5];
void qne(int k){
	int j=0,len1=s[k][1].size();
	for(int i=2;i<len1;i++){
		while(j&&s[k][1][i]!=s[k][1][j+1]) j=ne[k][j];
		if(s[k][1][i]==s[k][1][j+1]) j++;
		ne[k][i]=j;
//		cout<<ne[k][i]<<" ";
	}
//	cout<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][1];s[i][1]=" "+s[i][1];
		cin>>s[i][2];s[i][2]=" "+s[i][2];
		qne(i);
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		cin>>q[i][1];q[i][1]=" "+q[i][1];
		cin>>q[i][2];q[i][2]=" "+q[i][2];
		int lenq1=q[i][1].size()-1;
		int lenq2=q[i][2].size()-1;
		for(int j=1;j<=n;j++){
			int tmp=0;
			int id=0,len1=s[j][1].size()-1,len2=s[j][2].size()-1;
			for(int k=1;k<=lenq1;k++){
				while(id&&q[i][1][k]!=s[j][1][id+1]) id=ne[k][id];
				if(q[i][1][k]==s[j][1][id+1]) id++;
				if(id==len1){
					tmp=k-id+1;
				}
			}
			if(!tmp) continue;
			bool fa=0;
			int t=1;
			while(t<=lenq2){
				if(t==tmp){
					for(int tt=1;tt<=len2;tt++){
						if(s[j][2][tt]!=q[i][2][t++]){
							fa=1;
							break;
						}
					}
					continue;
				}
				if(q[i][1][t]!=q[i][2][t++]){
					fa=1;
					break;
				}
			}
			if(!fa) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
