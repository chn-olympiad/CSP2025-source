#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
const int M=5e6+10;
int n,q;
string s1[N],s2[N];
int ne1[M],ne2[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i]; 
	}
	while(q--){
		int res=0;
		string t1,t2;
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		int len=t1.size();
		int L=len,R=0;
		for(int i=1;i<len;i++){
			if(t1[i]!=t2[i]) L=min(L,i),R=i;
		}
		ne1[0]=ne1[1]=ne2[0]=ne2[1]=0;
		for(int i=2,j=0;i<=len;i++){
			while(j && t1[i]!=t1[j+1]) j=ne1[j];
			if(t1[i]==t1[j+1]) j++;
			ne1[i]=j;
		}
		for(int i=2,j=0;i<=len;i++){
			while(j && t2[i]!=t2[j+1]) j=ne2[j];
			if(t2[i]==t2[j+1]) j++;
			ne2[i]=j;
		}
//		cout<<L<<" "<<R<<endl;
		for(int x=1;x<=n;x++){
			int pt=s1[x].size()-1;
			for(int i=1,j1=0,j2=0;i<=len;i++){
				while(j1 && t1[i]!=s1[x][j1+1]) j1=ne1[j1];
				while(j2 && t2[i]!=s2[x][j2+1]) j2=ne2[j2];
				if(t1[i]==s1[x][j1+1]) j1++;
				if(t2[i]==s2[x][j2+1]) j2++;
				if(j1==pt && j2==pt){
					if(i>=R && i-pt+1<=L) res++;
//					cout<<i<<" "<<x<<endl;
				}
				if(j1==pt) j1=ne1[j1];
				if(j2==pt) j2=ne2[j2];
//				cout<<j1<<"*"<<j2<<endl;
			}
//			cout<<res<<endl; 
		}
		cout<<res<<'\n';
	}
	return 0;
}
