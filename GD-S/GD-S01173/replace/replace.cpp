#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}x[200005];
queue<int> q;
long long n,qs,ans;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>qs;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
	}
	while(qs--){
		ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			string t1=s1,t2="";
			while(t1.find(x[i].a)!=-1){
				q.push(t1.find(x[i].a));
				t1.erase(t1.find(x[i].a),1);
			}
			while(!q.empty()){
				t2="";
				int t=q.front();
				q.pop();
				for(int j=0;j<t;j++){
					t2=t2+s1[j];
				}
				t2=t2+x[i].b;
				for(int j=t+x[i].b.size();j<s1.size();j++){
					t2=t2+s1[j];
				}
				if(t2==s2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
