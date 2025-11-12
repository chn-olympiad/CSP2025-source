#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2;
int n,q,a,b,a1[200005],b1[200005],ans,len1,len2;
bool f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
		len1=s1[i].size();
		len2=s2[i].size();
		for(a1[i]=0;s1[i][1+a1[i]]==s2[i][1+a1[i]];a1[i]++){;}
		for(b1[i]=0;s1[i][len1-b1[i]]==s2[i][len2-b1[i]];b1[i]++){;}
		b1[i]--;
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		t1=' '+t1;
		t2=' '+t2;
		for(a=1;t1[a]==t2[a];a++){;}
		for(b=n;t1[b]==t2[b];b--){;}
//		cout<<a<<" "<<b<<endl;
		for(int i=1;i<=n;i++){
			f=0;
//			cout<<a1[i] <<" "<<b1[i] <<endl;
			for(int j=a-a1[i];j<=b+b1[i];j++){
				if(t1[j]!=s1[i][j-a+a1[i]+1]||t2[j]!=s2[i][j-a+a1[i]+1]){
					f=1;
//					cout<<i<<" "<<j<<endl;
					break;
				}
			}
			if(f==0){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 