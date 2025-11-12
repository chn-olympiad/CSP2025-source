#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	int from,to;
}pos[200010];
string s1[200010],s2[200010],t1[200010],t2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		for(int j=1;j<=s1[i].size()-1;++j){
			if(s1[i][j]=='b') pos[i].from=j; 
			if(s2[i][j]=='b') pos[i].to=j;
		}
//		cout<<pos[i].from<<" "<<pos[i].to<<endl;
	}
	for(int i=1;i<=q;++i){
		int ans=0;
		int from,to;
		cin>>t1[i]>>t2[i];
		t1[i]=" "+t1[i];
		t2[i]=" "+t2[i];
		for(int j=1;j<=t1[i].size();++j){
			if(t1[i][j]=='b') from=j;
			if(t2[i][j]=='b') to=j;
		}
//		cout<<from<<" "<<to<<endl;
//		if(q==1010){
//			cout<<t1[i]<<" "<<t2[i]<<endl;
//		}
		
		for(int j=1;j<=n;++j){
//		cout<<s1[j].size()-1-max(pos[j].from,pos[j].to)<<" "<<t1[i].size()-1-max(from,to)<<endl;
			if(pos[j].from-pos[j].to==from-to && min(pos[j].from,pos[j].to)<=min(from,to) && s1[j].size()-1-max(pos[j].from,pos[j].to)<=t1[i].size()-1-max(from,to)){
				ans++;
//				if(q==1010){
//					cout<<s1[j]<<" "<<s2[j]<<endl;
//				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*
2 1
abaa baaa
abaaa baaaa
aaaaabaa aaaabaaa
*/
