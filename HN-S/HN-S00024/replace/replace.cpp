#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
const ll p=1e9+7,b=27;
ll hs[N][2];
ll qp[M];
int f[M],f1[M],len[N];
ll hs2[M],hs3[M];
ll query(int l,int r,int inv){
	if(inv==0)return ((hs2[r]-hs2[l-1]*qp[r-l+1]%p)%p+p)%p;
	return ((hs3[r]-hs3[l-1]*qp[r-l+1]%p)%p+p)%p;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		for(auto c:s1){
			hs[i][0]=(hs[i][0]*b%p+(c-'a'+1))%p;
		}
		for(auto c:s2){
			hs[i][1]=(hs[i][1]*b%p+(c-'a'+1))%p;
		}
		len[i]=s1.size();
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}	
		int m=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=m;i++)f[i]=f1[i]=0;
		qp[0]=1;
		for(int i=1;i<=m;i++){
			if(t1[i]==t2[i])f[i]=1;
			else break;
		}
		for(int i=1;i<=m;i++)qp[i]=qp[i-1]*b%p;
		for(int i=1;i<=m;i++){
			hs2[i]=(hs2[i-1]*b%p+(t1[i]-'a'+1))%p;
			hs3[i]=(hs3[i-1]*b%p+(t2[i]-'a'+1))%p;
		}
		for(int i=m;i>=1;i--){
			if(t1[i]==t2[i])f1[i]=1;
			else break;
		}
		f[0]=1;
		f1[m+1]=1;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+len[i]-1<=m&&f[j-1];j++){
				if(f1[j+len[i]]){
					if(query(j,j+len[i]-1,0)==hs[i][0]&&query(j,j+len[i]-1,1)==hs[i][1]){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
