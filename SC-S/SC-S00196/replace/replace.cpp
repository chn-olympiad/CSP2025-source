#include <bits/stdc++.h>
using namespace std;
const int MAX_N=200010;
int n,q;
long long cnt=0;
char s1[MAX_N],s2[MAX_N],t1[MAX_N],t2[MAX_N],l1;
vector<int> e[MAX_N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int a,b;
		l1=strlen(s1);
		for(int i=0;i<l1;i++){
			if(s1[i]=='b'){
				a=i;
				break;
			}
		}
		for(int i=0;i<l1;i++){
			if(s2[i]=='b'){
				b=i;
				break;
			}
		}
		e[a].push_back(b);
	}
	while(q--){
		cin>>t1>>t2;
		l1=strlen(t1);
		int a,b;
		cnt=0;
		for(int i=0;i<l1;i++){
			if(t1[i]=='b'){
				a=i;
				break;
			}
		}
		for(int i=0;i<l1;i++){
			if(t2[i]=='b'){
				b=i;
				break;
			}
		}
		while(a>=0&&b>=0){
			for(int v:e[a]) if(v==b) cnt++;
			a--;
			b--;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}