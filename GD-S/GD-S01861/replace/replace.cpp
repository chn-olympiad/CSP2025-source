#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++){
			int x1=s1.find(s[j][1]);
			int x2=s2.find(s[j][2]);
			int x3=s[j][1].size();
			if(0<=x1 && x1<=s1.size() && x1==x2){
				string x4=s1;
				string x5=s2;
				x4.erase(x4.begin()+x1,x4.begin()+x1+x3);
				x5.erase(x5.begin()+x2,x5.begin()+x2+x3);
				if(x4==x5){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
