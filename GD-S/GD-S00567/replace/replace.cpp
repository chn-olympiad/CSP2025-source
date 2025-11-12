#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n=0;
int q=0;
struct node{
	string a;
	string b;
	bool vis=false;
}e[100000];
string s1;
string s2;
ll ans=0;
bool vis[100][100]={false};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>e[i].a>>e[i].b;
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		ll lens1=s1.length();
		for(int l=0;l<lens1;l++){
			for(int r=l+1;r<lens1;r++){
				string comp="";
				for(int i=l;i<=r;i++){
					comp+=s1[i];
				}
				for(int i=1;i<=n;i++){
					if(comp==e[i].a&&e[i].vis==false&&vis[l][r]==false){
						e[i].vis=true;
						vis[l][r]==true;
						ans++;
					}
				}
			}
		}
		cout<<ans-1<<endl;
	}
}
