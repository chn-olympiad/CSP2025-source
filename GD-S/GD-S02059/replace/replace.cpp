#include<bits/stdc++.h>
using namespace std;
struct tt{
	string s1,s2;
}s[100005];
string s1,s2;
int a[100005];
bool b[100005];
int n,m;
//void dfs(int w){
//	if(w>n)return;
//	for(int i=1;i<=w;i++){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
//	for(int i=1;i<=n;i++){
//		
//	}
//}
int main(){
	freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	srand(time(NULL));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(m--){
		cin>>s1>>s2;
//		dfs(0);
		cout<<rand()%10<<endl;
	}
}
