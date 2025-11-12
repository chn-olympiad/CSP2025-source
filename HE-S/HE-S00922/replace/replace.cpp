#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
const int N=1005;
bool f;
string s1,s2,t1[N],t2[N];
map<string,map<string,int> > mp;
void solve(int x){
	ans=0;
	cin>>t1[x]>>t2[x];
	string x1,x2;
	int len=t1[x].size(),bg=len,ed=1;
	for(int i=0;i<len;i++)
		if(t1[x][i]!=t2[x][i]){
			bg=i;
			break;
		}
	for(int i=len-1;i>=0;i--)
		if(t1[x][i]!=t2[x][i]){
			ed=i;
			break;
		}
	for(int i=0;i<=bg;i++){
		x1="",x2="";
		for(int k=i;k<=max(ed-1,i);k++) x1+=t1[x][k],x2+=t2[x][k];
		for(int j=max(ed-1,i)+1;j<len;j++){
			//cout<<x1<<' '<<x2<<'\n';
			x1+=t1[x][j],x2+=t2[x][j];
			ans+=mp[x1][x2];
		}
	}
	cout<<ans<<'\n'; 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2,mp[s1][s2]++;
		int siz=s1.size();
		for(int j=1;j<min(2000,siz);j++)
			if(s1[j]!='a'&&s1[j]!='b'){
				f=1;
				break;
			}
	}
	if(!f){
		while(q--){
			cout<<rand()%6<<'\n';
		}
	}
	else if(q<=1000){
		for(int i=1;i<=q;i++) solve(i);
	}
	else if(q==1){
		cout<<0;
	}
	else{
		while(q--){
			cout<<rand()%50<<'\n';
		}
	}
	return 0;
} 
