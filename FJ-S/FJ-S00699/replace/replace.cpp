#include<bits\stdc++.h>
using namespace std;
int n,cnt,m;
string s[11451][3],q[11451][3];
bool flag[1145][1145];
struct twoxz{
	int left,right,lefft,righht;
}a[114514],b[114514];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='b')a[i].left=j,a[i].right=s[i][1].size()-j-1;
		}
		for(int j=0;j<s[i][2].size();j++){
			if(s[i][2][j]=='b')a[i].lefft=j,a[i].righht=s[i][2].size()-j-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>q[i][1]>>q[i][2];
		int ans=0;
		for(int j=0;j<q[i][1].size();j++){
			if(q[i][1][j]=='b')b[i].left=j,b[i].right=q[i][1].size()-j-1;
		}
		for(int j=0;j<q[i][2].size();j++){
			if(q[i][2][j]=='b')b[i].lefft=j,b[i].righht=q[i][2].size()-j-1;
		}
		for(int j=1;j<=n;j++){
			if(b[i].lefft==b[i].left-a[j].left+a[j].lefft&&b[i].righht==b[i].right-a[j].right+a[j].righht&&b[i].left>=a[j].left&&b[i].right>=a[j].right)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
