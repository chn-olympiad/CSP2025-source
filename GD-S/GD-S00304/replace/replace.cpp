#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n,q,l,r,ll[N],rr[N],ans;
string s1[N],s2[N],s,t,ss,tt,s11[N],s22[N];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
		ll[i]=0,rr[i]=s1[i].size()-1,s11[i]=s22[i]="";
		while(s1[i][ll[i]]==s2[i][ll[i]]) ll[i]++;
		while(s1[i][rr[i]]==s2[i][rr[i]]) rr[i]--;
		for(int j=ll[i];j<=rr[i];j++) s11[i]+=s1[i][j],s22[i]+=s2[i][j];
	}while(q--){
		cin>>s>>t;
		l=0,r=s.size()-1,ss=tt="",ans=0;
		while(s[l]==t[l]) l++;
		while(s[r]==t[r]) r--;
		for(int i=l;i<=r;i++) ss+=s[i],tt+=t[i];
		for(int i=1;i<=n;i++){
			if(s11[i]==ss&&s22[i]==tt&&s.size()>=s1[i].size()){
				int p=1;
				for(int j=ll[i]-1,k=l-1;j>=0&&k>=0;j--,k--){
					if(s1[i][j]!=s[k]){
						p=0;
						break;
					}
				}int sizz1=s1[i].size(),sizz2=s.size();
				for(int j=rr[i]+1,k=r+1;j<sizz1 && k<sizz2;j++,k++){
					if(s1[i][j]!=s[k]){
						p=0;
						break;
					}
				}ans+=p;
			}
		}cout<<ans<<endl;
	}return 0;
}
