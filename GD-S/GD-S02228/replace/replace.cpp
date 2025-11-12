#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int n,q;
string s[200010][2];
string t1,t2;
unordered_map<ll,unordered_map<ll,int>> num;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++){
		ll v1=0,v2=0;
		int len=s[i][0].length();
		for(int j=0;j<len;j++){
			v1*=29;v2*=29;
			v1+=s[i][0][j]-'a'+1;v2+=s[i][1][j]-'a'+1;
		}
//		cout<<'*'<<v1<<' '<<v2<<endl;
		num[v1][v2]++;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.length();
		int fl=0,fr=len-1;
		while(fl<len-1&&t1[fl]==t2[fl]) fl++;
		while(fr>0&&t1[fr]==t2[fr]) fr--;
		long long ans=0;
		for(int i=0;i<=fl;i++){
			ll v1=0,v2=0;
			for(int j=i;j<=len-1;j++){
				v1*=29;v2*=29;
				v1+=t1[j]-'a'+1;v2+=t2[j]-'a'+1;
				if(j>=fr) ans+=num[v1][v2];
//				cout<<i<<' '<<j<<' '<<v1<<' '<<v2<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
