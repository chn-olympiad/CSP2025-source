#include <bits/stdc++.h>
using namespace std;
int cnt,n,q;
struct node{
	vector<int> ans;
	int nxt[30];
};
node e;
vector<node> vec[200005][2];
unordered_map<string,int> mp;
void take(int x,string s1,string s2){
	int d1,d2;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			d1=i;
			break;
		}
	}
	for(int i=s1.size()-1;i>=0;i--){
		if(s1[i]!=s2[i]){
			d2=i;
			break;
		}
	}
	string str=s1.substr(d1,d2-d1+1)+"#"+s2.substr(d1,d2-d1+1);
	int id=mp[str];
	if(id==0){
		id=mp[str]=++cnt;
		vec[id][0].push_back(e);
		vec[id][1].push_back(e);
	}
	int now=0;
	if(d1==0) vec[id][0][0].ans.push_back(x);
	if(d2==s1.size()-1)vec[id][1][0].ans.push_back(x);
	for(int i=d1-1;i>=0;i--){
		if(vec[id][0][now].nxt[s1[i]-'a']==0){
			vec[id][0][now].nxt[s1[i]-'a']=vec[id][0].size();
			vec[id][0].push_back(e);
		}
		now=vec[id][0][now].nxt[s1[i]-'a'];
		if(i==0){
			vec[id][0][now].ans.push_back(x);
		}
	}
	now=0;
	for(int i=d2+1;i<s1.size();i++){
		if(vec[id][1][now].nxt[s1[i]-'a']==0){
			vec[id][1][now].nxt[s1[i]-'a']=vec[id][1].size();
			vec[id][1].push_back(e);
		}
		now=vec[id][1][now].nxt[s1[i]-'a'];
		if(i==s1.size()-1){
			vec[id][1][now].ans.push_back(x);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<=29;i++) e.nxt[i]=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2){
			continue;
		}
		take(i,s1,s2);
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int d1,d2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				d1=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				d2=i;
				break;
			}
		}
		string str=s1.substr(d1,d2-d1+1)+"#"+s2.substr(d1,d2-d1+1);
		int id=mp[str];
		if(id==0){
			printf("0\n");
			continue;
		}
		int now=0;
		vector<int> G1,G2;
		if(d1==0){
			for(int j=0;j<vec[id][0][now].ans.size();j++){
					G1.push_back(vec[id][0][now].ans[j]);	
				}
		}
		if(d2==s1.size()-1){
			for(int j=0;j<vec[id][1][now].ans.size();j++) G2.push_back(vec[id][1][now].ans[j]);
		}
		for(int i=d1-1;i>=0;i--){
			for(int j=0;j<vec[id][0][now].ans.size();j++){
				G1.push_back(vec[id][0][now].ans[j]);	
			}
			//cout<<now<<endl;
			if(vec[id][0][now].nxt[s1[i]-'a']==0){
				break;
			}
			now=vec[id][0][now].nxt[s1[i]-'a'];
			if(i==0) 
				for(int j=0;j<vec[id][0][now].ans.size();j++){
					G1.push_back(vec[id][0][now].ans[j]);	
				}
		}
		now=0;
		for(int i=d2+1;i<s1.size();i++){
			for(int j=0;j<vec[id][1][now].ans.size();j++) G2.push_back(vec[id][1][now].ans[j]);
			if(vec[id][1][now].nxt[s1[i]-'a']==0){
				break;
			}
			now=vec[id][1][now].nxt[s1[i]-'a'];
			if(i==s1.size()-1){
				for(int j=0;j<vec[id][1][now].ans.size();j++) G2.push_back(vec[id][1][now].ans[j]);
			}
		}
		//for(int i=0;i<G2.size();i++) cout<<G2[i]<<endl;
		for(int i=0;i<G2.size();i++) G1.push_back(G2[i]);
		int last=0;
		sort(G1.begin(),G1.end());
		for(int i=1;i<G1.size();i++) if(G1[i]==G1[i-1]) last++;
		printf("%d\n",last);
	}
	return 0;
}
