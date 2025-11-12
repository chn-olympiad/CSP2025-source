#include<bits/stdc++.h>
using namespace std;
int n,q,L,R,k,sum;
int l[200005];
string s1[200005],s2[200005];
string t1,t2;
int fo(int w,int p){
	if(p<=L&&R<=p+l[w]-1){
		int ttt=1;
		for(int i=p;i<=p+l[w]-1;i++){
			if(s2[w][ttt]!=t2[i]){
				return 0;
			}
			ttt++;
		}
		return 1;
	}
	return 0;
}
void run(){
	for(int i=1;i<=n;i++){
		if(l[i]<(R-L+1)){
			continue;
		}
		int g=1; 
		for(int j=1;j<=k;j++){
			g=1;
			int wj=j;
			while(s1[i][g]==t1[wj]&&g<=l[i]&&wj<=k){
				g++;
				wj++;
			}
			if(g==l[i]+1){
				int tt=fo(i,j);
				if(tt==1){
					sum++;	
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
		l[i]=s1[i].size()-1;
	}
	while(q--){
		L=0,R=0,sum=0;
		cin>>t1>>t2;
		t1=" "+t1;
		t2=" "+t2;
		k=t1.size()-1;
		for(int i=1;i<=k;i++){
			if(t1[i]!=t2[i]){
				if(L==0){
					L=i;
				}
				R=i;
			}
		}
		run();
		cout<<sum<<"\n";
	}
	return 0;
}
/*
3 4
aa bb
b c
c d
aa bb
aa b
a c
b a
*/
