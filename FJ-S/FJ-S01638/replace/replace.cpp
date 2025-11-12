#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,q;
map<string,string> cnt;
map<string,bool> vis;
map<pair<string,string>,int> sum;
string s1,s2;
string s;
string sx;
int ans,nt;
bool vis1[10010][10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		cnt[s1]=s2;
		sum[{s1,s2}]++;
	 } 
	while(q--){
		cin>>s1>>s2;
		ans=0;
		nt=s1.size();
//		for(int i=0;i<nt-1;i++){
//			for(int j=0;j+i+1<=nt;j++){
//				s=sx="";
//				for(int k=0;k<i;k++){
//					s+=s1[k];
//				}
//				for(int k=i;k<nt-j;k++){
//					sx+=s1[k];
//				}
//				if(cnt[sx]!=""){
//					
//					s+=cnt[sx];
//					for(int k=nt-j;k<nt;k++){
//						s+=s1[k];
//					}
////					cout<<i<<' '<<j<<' '<<nt-i-j<<' '<<s<<endl;
//					if(s==s2) ans++;
//				}
//				
//			}
//		}
		for(int i=0;i<nt;i++){
			s="";
			int j=i;
			while((cnt[s]=="")&&j<=nt){
				s+=s1[j];
				j++;
			} 
//			cout<<i<<' '<<j<<endl<<endl;
			
			if(j==nt+1||(vis[s]&&vis1[i][j])) continue;
			vis1[i][j]=1;
			s.erase(j-i,1);
			vis[s]=1;
			sx="";
			for(int k=0;k<i;k++){
				sx+=s1[k];
			}
			sx+=cnt[s];
			for(int k=j;k<nt;k++){
				sx+=s1[k];
			}
			if(sx==s2){
				ans+=sum[{s,cnt[s]}];
			} 
//			cout<<i<<' '<<j<<' '<<s<<' '<<sx<<' '<<"cnm"<<endl;
			i--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
