#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[500005][4];
string s1,s2;
int t,a[5000005];
bool check(int l,int r,int x){
	int d=0;
	for(int i=l;i<=r;i++,d++){
		if(s[x][1][d]!=s1[i]) return 0;
	}
	d=0;
	for(int i=l;i<=r;i++,d++){
		if(s[x][2][d]!=s2[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	
	while(q--){
		int ans=0;
		t=0;
		cin>>s1>>s2;
	
		s1=' '+s1;
		s2=' '+s2;
		for(int i=1;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				a[++t]=i;
			} 
		}
		int mi=a[t]-a[1]+1;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()<mi) continue;
			for(int j=1;j<=n;j++){
				if(j<=a[1]&&j+s[i][1].size()-1>=a[t]){
					if(check(j,j+s[i][1].size()-1,i)==1) ans++;
				}
				else if(j+s[i][1].size()-1>n)break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
