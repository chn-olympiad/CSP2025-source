#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,q,cnt;
string str1[N],str2[N],a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
	}
	while(q--){
		cnt=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			if(a.find(str1[i])!=-1){
				string c=a;
				c.replace(a.find(str1[i]),str1[i].size(),str2[i]);
				if(c==b)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
