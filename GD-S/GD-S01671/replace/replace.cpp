#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,cnt;
struct stu{
	string s1,s2;
}node[N];
map<string,int>ds;//¸³×Ö·û´®hashÖµ
vector<int>p[N];//s1ÊÇ¸Ã×Ö·û´®µÄÆ¥Åä±àºÅ 
int main(){
	//16£º10-17£º28 ¼Ù×ö·¨ expect:0pts 
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]&&l<=r)l++;
		while(s1[r]==s2[r]&&l<=r)r--;
		for(int j=l;j<=r;j++){
			node[i].s1+=s1[j];
			node[i].s2+=s2[j];
		}
		//cout<<node[i].s1<<" "<<node[i].s2<<endl;
		if(!ds[node[i].s1])ds[node[i].s1]=++cnt;
		p[ds[node[i].s1]].push_back(i);
	}
	while(q--){
		int sum=0; 
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=0,r=t1.size();
		while(t1[l]==t2[l]&&l<=r)l++;
		while(t1[r]==t2[r]&&l<=r)r--;
		string ans1="",ans2="";
		for(int i=l;i<=r;i++){
			ans1+=t1[i];
			ans2+=t2[i];
		}
		//cout<<ans1<<" "<<ans2<<endl; 
		int u=ds[ans1];
		for(int i=0;i<p[u].size();i++){
			//cout<<p[u][i]<<endl;
			if(node[p[u][i]].s2==ans2)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
