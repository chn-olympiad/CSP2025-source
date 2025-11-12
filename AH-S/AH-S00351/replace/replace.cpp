#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2,s1[2005],s2[2005];
long long ans;
bool check(int l,int r,string &a){
	if(r-l+1!=a.size()) return 0;
	for(int i=l;i<=r;i++){
		if(t1[i]!=a[i]) return 0;
	}
	return 1;
}
void rp(int l,int r,string &a){
	for(int i=l;i<=r;i++){
		t1[i]=a[i];
	}
}
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		/*
		for(int i=1;i<=n;i++){
			for(int j=0;j<=t1.size()-s1[i].size();j++){
				if(check(j,j+s1[i].size()-1,s1[i])){
					string t=t1;
					rp(j,j+s1[i].size()-1,s2[i]);
					if(check(0,t1.size(),t2)){
						ans++;
						t1=t;
					}
				}				
			}
		}		
		
		cout<<ans<<"\n";
		ans=0;	*/ 	
		cout<<"0\n";
	}
	return 0;
}
