#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define st first
#define nd second
const int N=1e5+5,M=7.5e2+5;
/*vector<int>getlps(string p){
	int n=p.size(),len=0;
	vector<int>lps(n);
	for(int i=1;i<n;){
		if(p[i]==p[len]){
			lps[i++]=++len;
		}else if(len>0){
			len=lps[len-1];
		}else{
			i++;
		}
	}
}int kmp(string s,string p){
	int n=s.size(),m=p.size();
	vector<int> lps=getlps(p);
	cout<<s<<p<<endl;
	for(int i=0,j=0;i<n;){
		cout<<s[i]<<p[j]<<endl;
		if(s[i]==p[j]){
			i++,j++;
			if(j==m){
				return i-j;
			}
		}else if(j>0){
			j=lps[j-1];
		}else{
			i++;
		}
	}return -1;
}*/
int n,q;
map<string,string>ma;
map<string,bool>vis;
string t1,t2;
int bfs(){
	int ans=0;
	queue<string>q;
	q.push(t1);
	while(q.size()){
		string s=q.front();
		//cout<<"!!!!!!!!!";
		//cout<<s<<"!!!"<<endl;
		q.pop();
		/*if(s==t2){
			ans++;
			continue;
		}*/
		if(!vis[s]&&s.size()<=t2.size()){
			vis[s]=true;
			for(auto&[p1,p2]:ma){
				ll t=0;
				t=s.find(p1,t);
				//cout<<s<<' '<<p1<<' '<<t<<endl;
				if(t!=-1){
					string ttt="";
					for(int i=0;i<s.size();i++){
						if(!islower(s[i]))continue;
						if(i==t){
							i+=p1.size();
							ttt+=p2;
						}
						ttt+=s[i];
					}
					//cout<<"!!!!"<<p1<<' '<<t2<<' '<<ttt<<' '<<((ttt==t2)?"Y":"N")<<endl;
					if(ttt==t2||ttt==t2+' '||ttt==t2+"  "){
						ans++;
						//cout<<ans<<"!!!!";
					}else q.push(ttt);
				}
			}
		}
	}return ans;
} 
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		ma[t1]=t2;
		//cout<<t1<<' '<<t2<<'!'<<endl;
	}while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size())cout<<"0\n";
		else cout<<bfs()<<'\n';
	}
}
int main(){
	//string s="91912912",t="912";
	//cout<<s.find(t,2);
	freopen("replace.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();cout<<flush;
	fclose(stdin);fclose(stdout); 
	return 0;
} 
