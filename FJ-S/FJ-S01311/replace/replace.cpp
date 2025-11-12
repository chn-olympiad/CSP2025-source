#include<bits/stdc++.h>
using namespace std;
string ni[220000],nj[220000],qi[220000],qj[220000]; 
string nim[220000],njm[220000],qim[220000],qjm[220000];
int nl[220000],nr[220000],ql[220000],qr[220000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ni[i]>>nj[i];
		int len=ni[i].size();
		int l=len-1,r=0;
		for(int j=len-1;j>=0;j--){
			if(ni[i][j]!=nj[i][j]){
				l=j;
			}
		}
		for(int j=0;j<len;j++){
			if(ni[i][j]!=nj[i][j])r=j;
		}
		nim[i]=ni[i].substr(l,r-l+1);
		njm[i]=nj[i].substr(l,r-l+1);
		nl[i]=l;
		nr[i]=r;
	}
	for(int i=1;i<=q;i++){
		cin>>qi[i]>>qj[i];
		int len=qi[i].size();
		int l=len-1,r=0;
		for(int j=len-1;j>=0;j--){
			if(qi[i][j]!=qj[i][j])l=j;
		}
		for(int j=0;j<len;j++){
			if(qi[i][j]!=qj[i][j])r=j;
		}
		qim[i]=qi[i].substr(l,r-l+1);
		qjm[i]=qj[i].substr(l,r-l+1);
		ql[i]=l;
		qr[i]=r;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(nim[j]==qim[i] && njm[j]==qjm[i]){
				int rq=qj[i].size()-qr[i];
				int rn=nj[j].size()-nr[j];
				if(ql[i]>=nl[j] && rq>=rn){
					rq=qj[i].size()-rq+rn;
					int lq=rq-nj[j].size();
					if(qj[i].substr(lq,rq-lq)==nj[j])ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
