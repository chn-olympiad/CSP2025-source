#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n,q;
string s[200005][2],t[200005][2];
const int base=1009;
unsigned int pw[200005],hs[200005][2],ht[200005][2];
signed main(){
	ios::sync_with_stdio(false);                                                                
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int l1=0,l2=0;
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l1+=(s[i][0].size()+s[i][1].size());
		for(int j=s[i][0].size()-1;j>=0;j--){
			hs[i][0]+=pw[s[i][0].size()-j-1]*s[i][0][j];
			hs[i][1]+=pw[s[i][0].size()-j-1]*s[i][1][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		l2+=(t[i][0].size()+t[i][1].size());
	}
	for(int i=1;i<=q;i++){
		if(t[i][0].size()!=t[i][1].size()){
			cout<<0<<endl;
			continue;
		}
		int sum=0;
		int len=t[i][0].size();
		for(int j=0;j<=len;j++)ht[j][0]=ht[j][1]=0;
		for(int j=len-1;j>=0;j--){
			ht[j][0]=ht[j+1][0]+pw[len-j-1]*t[i][0][j];
			ht[j][1]=ht[j+1][1]+pw[len-j-1]*t[i][1][j];
		}
		for(int k=1;k<=n;k++){
			int subl=s[k][0].size();
			for(int j=0;j<len;j++){
				if(j+subl>len)break;
				unsigned int t1l=ht[0][0]-ht[j][0],t1m=ht[j][0]-ht[j+subl][0],t1r=ht[j+subl][0];
				unsigned int t2l=ht[0][1]-ht[j][1],t2m=ht[j][1]-ht[j+subl][1],t2r=ht[j+subl][1];
				if(t1l==t2l&&t1r==t2r&&t1m==hs[k][0]*pw[len-j-subl]&&t2m==hs[k][1]*pw[len-j-subl])sum++;
				if(t[i][0][j]!=t[i][1][j])break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
