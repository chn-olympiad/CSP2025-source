//GZ-S00218 贵阳市白云区华师一学校 李坤元 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
vector<char> s[N][3],t[N][3];
int idx[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	char cc;
	scanf("%c",&cc);
	for(int i=1;i<=n;i++){
		char x;
		while(1){
			scanf("%c",&x);
			if(x==' ') break;
			s[i][1].push_back(x);
		}
//		cout<<"||";
		while(1){
			scanf("%c",&x);
			if(x=='\n') break;
			s[i][2].push_back(x);
		}
	}
	for(int i=1;i<=q;i++){
		char x;
		while(1){
			scanf("%c",&x);
			if(x==' ') break;
			t[i][1].push_back(x);
		}
//		cout<<"||";
		while(1){
			scanf("%c",&x);
			if(x=='\n') break;
			t[i][2].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]==s[i][2][j]) idx[i]++;
			else break;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=s[i][1].size()-1;j>=0;j--){
			if(s[i][1][j]==s[i][2][j]) s[i][1].pop_back(),s[i][2].pop_back();
			else break;
		}
	}
	
	for(int i=1;i<=q;i++){
		int ans=0;
		int l,r;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!=t[i][2][j]){
				l=j;
				break;
			}
		}
		for(int j=t[i][1].size()-1;j>=0;j--){
			if(t[i][1][j]!=t[i][2][j]){
				r=j;
				break;
			}
		}
//		cout<<l<<' '<<r<<endl<<endl;
		for(int j=1;j<=n;j++){
//			cout<<s[j][1].size()<<' '<<idx[j]<<endl;
			if(r-l+1!=s[j][1].size()-idx[j]) continue;
//			cout<<"||"<<endl;
			bool flag=true;
			for(int k=0;k<s[j][1].size()-idx[j];k++){
				if(t[i][1][l+k]!=s[j][1][k+idx[j]]) {flag=false;break;}
				if(t[i][2][l+k]!=s[j][2][k+idx[j]]) {flag=false;break;}
			}
			if(flag) ans++;
		} 
		cout<<ans<<endl;
	} 
	return 0;
}
