#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2.5e6+5,B=1000;
int n,q;
string s[N][2],t[N][2];
unsigned long long p[M];
vector<unsigned long long> hshs[N][2],hsht[N][2];
int len;
unsigned long long gets(int l,int r,int i,int op){
	return hshs[i][op][r]-hshs[i][op][l-1]*p[r-l+1];
}
unsigned long long gett(int l,int r,int i,int op){
	return hsht[i][op][r]-hsht[i][op][l-1]*p[r-l+1];
}
int L[N],R[N];
bool vis[N];
int id_cnt;
int nd[N],nd_cnt; 
struct others{
	unsigned long long od,nw;
	int id;
}ot[N];
int ot_cnt;
int id[1005][1005];
unsigned long long aa,bb;
vector<int> hav1[N],hav2[N];
bool cc[1005][30][30],ccc[30][30];
int tim[N],TIM;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	p[0]=1;
	for(int i=1;i<=2500000;i++){
		p[i]=p[i-1]*13331;
	}
	cin>>n>>q;
	int sb=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
		hshs[i][0].push_back(0);
		hshs[i][1].push_back(0);
		for(int j=1;j<s[i][0].size();j++){
			hshs[i][0].push_back(hshs[i][0][j-1]*13331+s[i][0][j]);
			hshs[i][1].push_back(hshs[i][1][j-1]*13331+s[i][1][j]);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		t[i][0]=' '+t[i][0];
		t[i][1]=' '+t[i][1];
		hsht[i][0].push_back(0);
		hsht[i][1].push_back(0);
		for(int j=1;j<t[i][0].size();j++){
			hsht[i][0].push_back(hsht[i][0][j-1]*13331+t[i][0][j]);
			hsht[i][1].push_back(hsht[i][1][j-1]*13331+t[i][1][j]);
			if(t[i][0][j]!=t[i][1][j]){
				if(!L[i]){
					L[i]=j;
				}
				R[i]=j;
			}
		}
//		cerr<<L[i]<<' '<<R[i]<<'\n';
		if(R[i]-L[i]+1<=B){
			vis[R[i]-L[i]+1]=1;
			unsigned long long od=gett(L[i],R[i],i,0),nw=gett(L[i],R[i],i,1);
			if(!id[od%1000][nw%1000]){
				id[od%1000][nw%1000]=++id_cnt;
			}
			cc[R[i]-L[i]+1][t[i][0][R[i]]-'a'+1][t[i][1][R[i]]-'a'+1]=1;
			ccc[t[i][0][R[i]]-'a'+1][t[i][1][R[i]]-'a'+1]=1;
		}
		else{
			ot[++ot_cnt]={gett(L[i],R[i],i,0),gett(L[i],R[i],i,1),i};
		}
	}
	for(int i=1;i<=B;i++){
		if(vis[i]){
			nd[++nd_cnt]=i;
		}
	}
//	cerr<<nd_cnt<<' '<<ot_cnt<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<s[i][0].size();j++){
			if(!ccc[s[i][0][j]-'a'+1][s[i][1][j]-'a'+1]){
				continue;
			}
			for(int k=1;k<=nd_cnt;k++){
				if(nd[k]>j){
					break;
				}
				if(!cc[nd[k]][s[i][0][j]-'a'+1][s[i][1][j]-'a'+1]){
					continue;
				}
				aa=gets(j-nd[k]+1,j,i,0),bb=gets(j-nd[k]+1,j,i,1);
				if(id[aa%1000][bb%1000]){
					hav1[id[aa%1000][bb%1000]].push_back(i);
				}
			}
		}
		for(int j=1;j<=ot_cnt;j++){
			int len=R[ot[j].id]-L[ot[j].id]+1;
			for(int k=len;k<s[i][0].size();k++){
				if(gets(k-len+1,k,i,0)==ot[j].od){
					if(gets(k-len+1,k,i,1)==ot[j].nw){
						hav2[ot[j].id].push_back(i);
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(R[i]-L[i]+1<=B){
			unsigned long long od=gett(L[i],R[i],i,0),nw=gett(L[i],R[i],i,1);
			int ii=id[od%1000][nw%1000];
			int ans=0;
			TIM++;
			for(int j:hav1[ii]){
				if(tim[j]==TIM){
					continue;
				}
				tim[j]=TIM;
				aa=gets(1,s[j][0].size()-1,j,0),bb=gets(1,s[j][0].size()-1,j,1);
				for(int k=s[j][0].size()-1;k<t[i][0].size();k++){
					if(aa==gett(k-s[j][0].size()+2,k,i,0)&&bb==gett(k-s[j][0].size()+2,k,i,1)){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else{
			int ans=0;
			for(int j:hav2[i]){
				aa=gets(1,s[j][0].size()-1,j,0),bb=gets(1,s[j][0].size()-1,j,1);
				for(int k=s[j][0].size()-1;k<t[i][0].size();k++){
					if(aa==gett(k-s[j][0].size()+2,k,i,0)&&bb==gett(k-s[j][0].size()+2,k,i,1)){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
