#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a,b;
string s[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		int len=a.size(),ans=0,cnt=0;
		for(int i=1;i<=len;i++)
			for(int j=1;j<=n;j++){
				int Len=s[j][0].size(); 
				string c="",d="";
				for(int k=i;k<=i+Len-1;k++)
					c+=a[k],d+=b[k];
				if(c==s[j][0]&&d==s[j][1]){
					bool flag=false;
					for(int k=i+Len;k<=len;k++)
						if(a[k]!=b[k])
							flag=true;
					for(int k=1;k<i;k++)
						if(a[k]!=b[k])
							flag=true;
					if(!flag)
						ans++;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
