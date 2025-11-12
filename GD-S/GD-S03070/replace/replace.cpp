#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][3];
string t1,t2;
string pian(int l,int r,string s){
	string ans;
	ans=s[l];
	for(int i=l+1;i<=r;i++){
		ans=ans+s[i];
	}
	return ans;
}
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1];
		cin>>s[i][2];
	}
	for(;q;--q){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1==s[i][1]&&t2==s[i][2]){
				ans++;
				break;
			}
		}
		if(n<=100&&q<=100){
			for(int i=0;i<(int)t1.size();i++){
				for(int j=1;j<=n;j++){
					if(pian(0,i-1,t1)==pian(0,i-1,t2)&&pian(i+(int)s[j][1].size(),(int)t1.size()-1,t1)==pian(i+(int)s[j][1].size(),(int)t1.size()-1,t2)&&pian(i,i+(int)s[j][1].size()-1,t1)==s[j][1]&&pian(i,i+(int)s[j][1].size()-1,t2)==s[j][2]){
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
