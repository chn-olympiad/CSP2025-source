#include<bits/stdc++.h>
using namespace std;

int n,q,ans;
string s[200005][2];
string t[2];

string cut(string st,int l,int r){
	string ret="";
	for(int i=l;i<=r;i++)
		ret+=st[i];
	return ret;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replece.out","w",stdout);
	cin>>n>>q;
	int qc=q;
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--){
		ans=0;
		cin>>t[0]>>t[1];
		bool ansb[200005];
		memset(ansb,0,sizeof(ansb));
		for(int i=0;i<n;i++){
			int pos=0;
			bool con=false;
			int cntt=0;
			while((int)t[0].find(s[i][0],pos)!=-1){
				int tmp=t[0].find(s[i][0],pos);
				if( cut( t[1] , tmp , tmp+(int)s[i][1].length()-1 ) == s[i][1] )
					ansb[i]=1;

				if(cut(t[0],0,tmp-1)==cut(t[0],tmp+(int)s[i][1].length(),(int)t[0].length()-1) &&
					(
					(int)t[0].length() != (int)s[i][0].length()
					)){
					ansb[i]=0;
					con=true;
					break;
				}

				if(s[i][0]==s[i][1]){
					ansb[i]=0;
					con=true;
					break;
				}

				if(cntt>0){
					ansb[i]=0;
					con=true;
					break;
				}
						
				pos=tmp+1;
				cntt++;
			}
			if(con)continue;
			
		}
		for(int i=0;i<n;i++)
			ans+=(int)ansb[i];
		cout<<ans<<'\n';
	}
	return 0;
}