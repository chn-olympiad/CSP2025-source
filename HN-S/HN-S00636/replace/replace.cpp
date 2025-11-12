#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5e6+5;
int vis[N][2],tot=0,n1[N],n2[N],ha1[N],ha2[N],pw[N],l1[N],l2[N];
int get1(int l,int r){
	return ha1[r]-ha1[l-1]*pw[r-l+1];
}
int get2(int l,int r){
	return ha2[r]-ha2[l-1]*pw[r-l+1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=N-5;i++)pw[i]=pw[i-1]*131;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ull ha11,ha22;
		ha11=ha22=0;
		for(int j=0;j<s1.size();j++){
			ha11=ha11*131+s1[j];
		}
		for(int j=0;j<s2.size();j++){
			ha22=ha22*131+s2[j];
		}
		n1[i]=ha11,n2[i]=ha22;
		l1[i]=s1.size(),l2[i]=s2.size();
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			ha1[i]=ha1[i-1]*131+s1[i];
			vis[i][0]=vis[i][1]=0;
		}
		for(int i=0;i<s2.size();i++){
			ha2[i]=ha2[i-1]*131+s2[i];
		}
		int L,R;
		for(int i=0;i<min(s1.size(),s2.size());i++){
			if(s1[i]!=s2[i]){
				break;
			}
			vis[i][0]=1;
		}
		int A=s1.size()-1,B=s2.size()-1;
		vis[A+1][1]=1;
		while(A>=0&&B>=0){
			if(s1[A]!=s2[B])break;
//			cout<<A<<"\n";
			vis[A][1]=1;
			A--,B--;
		}
		int ans=0;
		int i=-1;
		for(int j=1;j<=n;j++){
			if(i+l1[j]>=s1.size()||i+l2[j]>=s2.size())continue;
			if(s1.size()-i-l1[j]!=s2.size()-i-l2[j])continue;
//			cout<<"-->"<<i+l1[j]<<"\n";
			if(vis[i+l1[j]][1]){
//				cout<<i<<" "<<j<<"\n";
				ans++;
			}
		}
		for(i=0;i<min(s1.size(),s2.size());i++){
			if(i!=0&&!vis[i-1][0])break;
			for(int j=1;j<=n;j++){
				if(i+l1[j]>=s1.size()||i+l2[j]>=s2.size())continue;
				if(s1.size()-i-l1[j]!=s2.size()-i-l2[j])continue;
//				cout<<i+l1[j]<<"\n";
				if(vis[i+l1[j]][1]&&get1(i,i+l1[j]-1)==n1[j]&&get2(i,i+l2[j]-1)==n2[j]){
//					cout<<i<<" "<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

