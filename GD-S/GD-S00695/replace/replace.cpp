#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1;
	string s2;
}arr[10000007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i].s1>>arr[i].s2;
	} 
	while(q--){
		int ans=0;
		string s;
		string m;
		cin>>s>>m;
		for(int i=1;i<=n;i++){
			if(int(s.find(arr[i].s1))!=-1&&int(m.find(arr[i].s2))!=-1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}

