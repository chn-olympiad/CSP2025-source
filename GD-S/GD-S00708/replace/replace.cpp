#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pss pair<string,string>
const int N=2e5+7;
int n,m;
pss s[N];
string cut(string a,int j,int b){
	string an;
	for(int i=j;i<j+b;i++){
		an.push_back(a[i]);
	}
	return an;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	string a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		int len=a.size();
		int ans=0;
		for(int k=1;k<=n;k++){
			int l=s[k].first.size();
			for(int j=0;j<=len-l;j++){
				if(a[j]==s[k].first[0]){
					string t=cut(a,j,l);
					if(t==s[k].first){
						string c;
						for(int q=0;q<len;q++){
							if(q==j){
								for(int p=0;p<l;p++)
									c.push_back(s[k].second[p]);
								q+=l-1;
							}
							else{
								c.push_back(a[q]);
							}
						}
//						cout<<c<<endl;
						if(c==b)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
