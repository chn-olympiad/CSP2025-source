#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[100005],s2[100005],t1,t2;
int sl[100005];
void exh(string a,string b,int l){
	int al=a.size(),bl=b.size();
	for(int i=l,j=0;i<al;i++,j++){
		a[i]=b[j];
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sl[i]=s1[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int tl=t1.size(),ans=0;
		for(int j=1;j<=n;j++){
			string b=t1;
			for(int k=0;k<=tl;k++){
				exh(t1,s1[j],k);
				if(b==t1) exh(t1,s2[j],k);
				if(t1==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
