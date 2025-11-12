#include <bits/stdc++.h>
using namespace std;
int n,q,s3[110];
string s1[110],s2[110],t;
void tihuan(int x,int y,int p,string *t){
	int tmp=s1[y].size();
	for(int i=x+tmp;i<p;i++)t[i-x]=t[i];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(int i=0;i<n;i++){
		int p1=s1[i].size(),p2=s2[i].size(),k;
		for(int j=0;j<min(p1,p2);j++)if(s1[j]!=s2[j])k++;
		s3[i]=k+p1-p2;
	}
	cin>>t;
	int p=t.size(),l=0;
	for(int i=0;i<p;i++){
		for(int j=0;j<n;j++){
			if(t.substr(i,s1[j].size())==s1[j]){
				tihuan(i,j,p,&t);
				p-=i;
				l+=s3[i];
			}
		}
	}
	cout<<l<<endl;
	return 0;
}
