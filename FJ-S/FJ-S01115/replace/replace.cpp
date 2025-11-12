#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string t1,t2;
string s[200005][3];
string t[200005][3];
long long sum[200005];
map<string,int> m;
string check1(int x,int y){
	string new_s="";
	for(int i=x;i<=y;i++) new_s+=t1[i];
	return new_s;
}
string check2(int x,int y){
	string new_s="";
	for(int i=x;i<=y;i++) new_s+=t2[i];
	return new_s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		m[s[i][1]]=i;
	}
	int t=0;
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			sum[++t]=0;
			continue;
		}
		int l=0,r=t1.size()-1;
		while(l<=r&&t1[l]==t2[l]) l++;
		while(l<=r&&t1[r]==t2[r]) r--;
		for(int i=0;i<=l;i++){
			int len=t1.size()-1;
			for(int j=len;j>=r;j--){
				string now_s=check1(i,j);
				string next_s=check2(i,j);
				if(m[now_s]){
					int x=m[now_s];
					if(s[x][2]==next_s) ans++;
				}
			}
		}
		sum[++t]=ans;
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
