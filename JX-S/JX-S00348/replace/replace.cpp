#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N];

int finds(string S,string s){
	for(int i=0;i<=(int)S.size()-(int)s.size();i++)
		if(S.substr(i,(int)s.size())==s) return i;
	return -1;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int sum=0;
		for(int i=1;i<=n;i++){
			int k=finds(t1,a[i]);
			if(k!=-1){
				string s=t1.substr(0,k)+b[i]+t1.substr(k+(int)b[i].size(),(int)t1.size()-k-(int)b[i].size());
				if(s==t2) sum++;
			}
		}cout<<sum<<'\n';
	}
	return 0;
}
