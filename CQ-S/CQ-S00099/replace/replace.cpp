#include<bits/stdc++.h>
using namespace std;
int n,q,len,mxl;
map<int,int> mp;
map<string,string> p;
string t1,t2,s1[200005],s2[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		p[s1[i]]=s2[i];
		int l=s1[i].size(),ac1=0,bc1=0,ac2=0,bc2=0,bx1,bx2;
		if(l>mxl) mxl=l;
		for(int j=0;j<l;j++){
			if(s1[i][j]=='b') bx1=i;
			ac1+=(s1[i][j]=='a'),bc1+=(s1[i][j]=='b');
			if(s2[i][j]=='b') bx2=i;
			ac2+=(s2[i][j]=='a'),bc2+=(s2[i][j]=='b');
		}
		if(ac1==l-1&&bc1==1&&ac2==l-1&&bc2==1) mp[bx2-bx1]++;
	}
	while(q--){
		cin>>t1>>t2;
		len=t1.size();
		int fid,bid,ac1=0,bc1=0,ac2=0,bc2=0,bx1,bx2;
		for(int i=0;i<len;i++){
			if(t1[i]=='b') bx1=i;
			ac1+=(t1[i]=='a'),bc1+=(t1[i]=='b');
			if(t2[i]=='b') bx2=i;
			ac2+=(t2[i]=='a'),bc2+=(t2[i]=='b');
		}
		if(ac1==len-1&&bc1==1&&ac2==len-1&&bc2==1){
			cout<<mp[bx2-bx1]<<"\n";
			continue;
		}
		for(int i=0;i<len;i++)
			if(t1[i]!=t2[i]){
				fid=i;
				break;
			}
		for(int i=len-1;i>=0;i--)
			if(t1[i]!=t2[i]){
				bid=i;
				break;
			}
		if(mxl<bid-fid+1){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<=fid;i++)
			for(int j=bid;j<len;j++){
				string ns1="",ns2="";
				for(int k=i;k<=j;k++) ns1+=t1[k],ns2+=t2[k];
				if(p[ns1]==ns2) ans++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
