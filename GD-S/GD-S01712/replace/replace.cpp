#include<bits/stdc++.h>
using namespace std;
const int N=200050;
string str1,str2,s1[N],s2[N],tmp;
int n,q,ans;
int main(){
	//freopen("replace2.in","r",stdin);//ÑùÀý
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		ans=0;
		cin>>str1>>str2;
		for(int i=1;i<=n;i++){
			tmp=str1;
			if(tmp.find(s1[i])==tmp.npos)continue;
			if(str2==tmp.replace(tmp.find(s1[i]),s1[i].size(),s2[i])){
				ans++;
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
}

