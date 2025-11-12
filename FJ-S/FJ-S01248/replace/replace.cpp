#include <bits/stdc++.h>
using namespace std;
int n,q,so[200005],st[200005],eo[200005],et[200005];
string si[200005][2],ti[100005][2],vb[200005],vd[200005],qw[200005],wq[200005];
void sfg(string a,string b,int j){
	int str=0,edn=0,o=0;
	string ss,ll;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			str=i;
			break;
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]!=b[i]){
			edn=i;
			break;
		}
	}
	so[j]=str;
	eo[j]=edn;
	for(int i=str;i<=edn;i++){
		vb[j][o]=a[i];
		vd[j][o]=b[i];
		o++;
	}
}
void gfs(string a,string b,int j){
	int str=0,edn=0,o=0;
	string ss,ll;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			str=i;
			break;
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]!=b[i]){
			edn=i;
			break;
		}
	}
	st[j]=str;
	et[j]=edn;
	for(int i=str;i<=edn;i++){
		qw[j][o]=a[i];
		wq[j][o]=b[i];
		o++;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>si[i][1]>>si[i][2];
		sfg(si[i][1],si[i][2],i);
	}
	for(int i=1;i<=q;i++){
		cin>>ti[i][1]>>ti[i][2];
		gfs(ti[i][1],ti[i][2],i);
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(qw[j]==vb[j]){
				for(int il=so[i];il<=eo[i];il++){
					ti[i][1][il]=vb[i][il];
				}
				bool f=true;
				for(int ir=0;ir<ti[i][1].size();ir++){
					if(ti[i][1][ir]!=ti[i][2][ir]){
						f=false;
						break;
					}
				}
				if(f){
					sum++;
				}
				
			}
		}
		sum=0;
		cout<<sum<<endl;
	}
	return 0;
} 


