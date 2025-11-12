#include<bits/stdc++.h>
using namespace std;
struct vid{
	string t1,t2;
}vid[200005];
int alfa1[27];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=0;i<n;i++){
		cin>>vid[i].t1>>vid[i].t1;
	}
	while(q--){
		int cnt=0;
		memset(alfa1,0,sizeof(alfa1));
		string s1,s2;
		cin>>s1>>s2;
		for (int i=0;i<sizeof(s1);i++){
			alfa1[s1[i]-'a']++;
			alfa1[s2[i]-'a']--;
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<sizeof(vid[i].t1);j++){
				alfa1[vid[i].t1[j]-'a']--;
				alfa1[vid[i].t2[j]-'a']++;
			}
			int flag=1;
			for (int j=0;j<26;j++){
				if(alfa1[j]!=0){
					flag=0;
				}
			}
			if(flag){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
