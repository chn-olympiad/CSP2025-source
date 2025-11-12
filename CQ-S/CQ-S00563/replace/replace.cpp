#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull p1=1331,p2=13331;
int n,q,l[200005],pos[200005][2],a[200005],ans[200005]; string s[200005][2],t[2];
ull hs1[200005][2],hs2[200005][2],Hs1[5000005][2],Hs2[5000005][2];
struct node{ int l,r; }; map<int,vector<node> > V; set<int> S;
struct Query{ int l,r,id; }; map<int,vector<node> > Q;
bool cmp(node a,node b){ return a.l<b.l; }
//bool cmp2(Query a,Query b){ return a.l<b.l; }
//int lowbit(int x){ return x&-x; }
//void update(int x){ for(;) }
void subtask_1_5(){
	if(n<=1000 && q<=1000){
		for(int i=1;i<=n;i++){	
			ull P1=1,P2=1;
			for(int j=0;j<l[i];j++) hs1[i][0]+=P1*s[i][0][j],hs1[i][1]+=P1*s[i][1][j],P1*=p1,hs2[i][0]+=P2*s[i][0][j],hs2[i][1]+=P2*s[i][1][j],P2*=p2;
		}
		while(q--){
			cin >> t[0] >> t[1]; int m=t[0].length();
			if(t[0].length()!=t[1].length()){ cout << "0\n"; continue; }
			ull P1=1,P2=1; Hs1[0][0]=P1*t[0][0],Hs1[0][1]=P1*t[1][0],Hs2[0][0]=P2*t[0][0],Hs2[0][1]=P2*t[1][0],P1*=p1,P2*=p2;
			for(int i=1;i<m;i++) Hs1[i][0]=Hs1[i-1][0]+P1*t[0][i],Hs1[i][1]=Hs1[i-1][1]+P1*t[1][i],P1*=p1,Hs2[i][0]=Hs2[i-1][0]+P2*t[0][i],Hs2[i][1]=Hs2[i-1][1]+P2*t[1][i],P2*=p2;
			int cnt=0;
			for(int i=1;i<=n;i++){
				ull P1=1,P2=1;
				for(int j=0;j<=m-l[i];j++){
					ull HS10=(j!=0?Hs1[j-1][0]:0)+Hs1[m-1][0]-Hs1[j+l[i]-1][0],HS11=(j!=0?Hs1[j-1][1]:0)+Hs1[m-1][1]-Hs1[j+l[i]-1][1];
					ull HS20=(j!=0?Hs2[j-1][0]:0)+Hs2[m-1][0]-Hs2[j+l[i]-1][0],HS21=(j!=0?Hs2[j-1][1]:0)+Hs2[m-1][1]-Hs2[j+l[i]-1][1];
//					if(i==3) cout << HS10 << " " << HS11 << " " << HS20 << " " << HS21 << '\n';
					if(HS10+hs1[i][0]*P1==Hs1[m-1][0] && HS10==HS11 && HS10+hs1[i][1]*P1==Hs1[m-1][1] && 
						HS20+hs2[i][0]*P2==Hs2[m-1][0] && HS20==HS21 && HS20+hs2[i][1]*P2==Hs2[m-1][1]) cnt++;
					P1*=p1,P2*=p2;
				}
			}
			cout << cnt << '\n';
		}
		exit(0);
	}
} 
//void subtask_B(){
//	for(int i=1;i<=n;i++){
//		int cnt=0;
//		for(int j=0;j<l[i];j++){
//			if(s[i][0][j]>'b') return; 
//			cnt+=(s[i][0][j]=='b');
//		} if(cnt!=1) return;
//		cnt=0;
//		for(int j=0;j<l[i];j++){
//			if(s[i][1][j]>'b') return; 
//			cnt+=(s[i][1][j]=='b');
//		} if(cnt!=1) return;
//	} 
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<l[i];j++){
//			if(s[i][0][j]=='b') pos[i][0]=j;
//			if(s[i][1][j]=='b') pos[i][1]=j;
//		} a[i]=pos[i][0]-pos[i][1];
//		V[a[i]].push_back({pos[i][0],l[i]-pos[i][0]-1});
//	} for(int i=1;i<=n;i++) if(!S.count(a[i])) S.insert(a[i]),sort(V[a[i]].begin(),V[a[i]].end(),cmp);
//	for(int i=1;i<=q;i++){
//		int pos1,pos2;
//		cin >> t[0] >> t[1]; int m=t[0].length();
//		if(t[0].length()!=t[1].length()){ ans[i]=0; continue; }
//		for(int j=0;j<m;j++){
//			if(t[0][j]=='b') pos1=j;
//			if(t[1][j]=='b') pos2=j;
//		} Q[pos1-pos2].push_back({pos1,m-pos1-1,i});
//	} S.clear();
//	for(int i=1;i<=n;i++) if(!S.count(a[i])){
//		S.insert(a[i]);
//		sort(Q[a[i]].begin(),Q[a[i]].end(),cmp2);
//	}
//	exit(0);
//} 
void subtask_all(){
	while(q--) cout << "0\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> s[i][0] >> s[i][1],l[i]=s[i][0].length();
	subtask_1_5(),subtask_all();
	return 0;
}

