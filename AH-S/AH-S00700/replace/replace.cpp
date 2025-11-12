#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,num,l[N],r[N];
string s1[N],s2[N],s1n[N],s2n[N],t1[N],t2[N];
vector<int> v[N];
map<string,int> ma;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		l[i]=-1,r[i]=-1;
		for(int j=0;j<len;j++){
			if(s1[i][j]!=s2[i][j]) {l[i]=j;break;}
		}
		for(int j=len-1;j>=0;j--){
			if(s1[i][j]!=s2[i][j]) {r[i]=j;break;}
		}
		if(l[i]!=-1){
			s1n[i]="",s2n[i]="";
			for(int j=l[i];j<=r[i];j++)
			s1n[i]+=s1[i][j],s2n[i]+=s2[i][j];
			if(ma[s1n[i]]) {
				int x=ma[s1n[i]];
				v[x].push_back(i);
			}
			else {
				num++;
				ma[s1n[i]]=num;
				v[num].push_back(i);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		int len=t1[i].size(),dfjk=t2[i].size(),ll=0,rr=t1[i].size()-1;
		if(len!=dfjk){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<len;j++){
			if(t1[i][j]!=t2[i][j]) {ll=j;break;}
		}
		for(int j=len-1;j>=0;j--){
			if(t1[i][j]!=t2[i][j]) {rr=j;break;}
		}
		string ss1="",ss2="";
		for(int j=ll;j<=rr;j++)
		ss1+=t1[i][j],ss2+=t2[i][j];
		if(ma[ss1]){
			int id=ma[ss1];int t=v[id].size(),ans=0;
			for(int j=0;j<t;j++){
				int c=v[id][j];int lenx=s1[c].size();int flag=1;
				int lnow=ll-l[c],rnow=rr+(lenx-r[c]-1);
				if(lnow<0||rnow>=len) continue;
				for(int k=0;k<lenx;k++)
					if(s1[c][k]!=t1[i][lnow+k]||s2[c][k]!=t2[i][lnow+k]) {flag=0;break;}
				ans+=flag;
			}
			cout<<ans<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
