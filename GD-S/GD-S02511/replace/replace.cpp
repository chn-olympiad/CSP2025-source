#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005],t1,t2;
int xxx[50000005][2],a,b;
bool f=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(q==1){
		cin>>t1>>t2;
		int p=0,p1=-1+t1.length();
		while(t1[p]==t2[p])
			p++;
		while(t1[p1]==t2[p1])
			p1--;
		for(int i=1;i<=n;i++){
			if(s1[i].length()!=s2[i].length()){
				continue;
			}
			for(int j=0;j<t1.length();j++){
				int f=1;
				if(j>p||p1>j+s1[i].length()){
					f=0;
				}
				for(int k=0;f&&(k<s1[i].length())&&(j+k<t1.length());k++){
					if(t1[j+k]!=s1[i][k]||t2[j+k]!=s2[i][k]){
						f=0;
						break;
					}
				}
				ans+=f;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n&&(!f);i++){
			if(s1[i].length()!=s2[i].length()){
				continue;
			}
			for(int j=0;j<s1[i].length();j++){
				if((s1[i][j]!='a'&&s1[i][j]!='b')||(s2[i][j]!='a'&&s2[i][j]!='b')){
					f=1;
					break;
				}
				if(s1[i][j]=='b'){
					xxx[i][0]=j;
				}
				if(s2[i][j]=='b'){
					xxx[i][1]=j;
				}
			}
		}
		if(f){
			for(int i=1;i<=q;i++){
				cout<<0<<endl;
			}
		}else{
			for(int i=1;i<=q;i++){
				cin>>t1>>t2;
				for(int j=0;j<t1.length();j++){
					if(t1[j]=='b'){
						a=j;
					}
					if(t2[j]=='b'){
						b=j;
					}
				}
				ans=0;
				for(int j=1;j<=n;j++){
					if(s1[i].length()!=s2[i].length()){
						continue;
					}
					if(xxx[j][0]<=a&&xxx[j][1]<=b&&((xxx[j][0]-xxx[j][1])==(a-b))){
						ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
		
	}
	return 0;
}
