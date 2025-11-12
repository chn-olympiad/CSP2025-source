#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;


struct node{
	int id,st,nex;
	string s1,s2;
}clr,s[N];

map<string,map<string,node> > mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1,l,r;i<=n;i++){	
		cin>>s[i].s1>>s[i].s2;
		for(l=0;s[i].s1[l]==s[i].s2[l];l++);
		for(r=s[i].s1.size()-1;s[i].s1[r]==s[i].s2[r];r--);
		int len=r-l+1;
		string ss1,ss2;
		for(int j=l;j<=r;j++){
			ss1+=s[i].s1[j];
			ss2+=s[i].s2[j];
		}
		s[i].id=i,s[i].nex=0,s[i].st=-l;
		if(mp[ss1][ss2].id==0){
			mp[ss1][ss2]=s[i];
		}else{
			s[i].nex=mp[ss1][ss2].id;
			mp[ss1][ss2]=s[i];
		}
	}
	string q1,q2;
	while(q--){
		cin>>q1>>q2;
		int l,r;
		bool ff=1;
		for(l=0;q1[l]==q2[l];l++) if(q1[l]==q2[l]&&q1[l]!='a') ff=0;
		for(r=q1.size()-1;q1[r]==q2[r];r--) if(q1[r]==q2[r]&&q1[r]!='a') ff=0;
		if(ff&&l==r&&q1[l]=='b') ff=1;
		else ff=0;
		int len=r-l+1;
		string ss1,ss2;
		for(int j=l;j<=r;j++){
			ss1+=q1[j];
			ss2+=q2[j];
		}
		if(mp[ss1][ss2].id==0) printf("0\n");
		else if(ff){
			int sum=0,idd=mp[ss1][ss2].id;
			while(idd!=0){
				if(l+s[idd].st<0||l+s[idd].st+s[idd].s1.size()>q1.size()){
					idd=s[idd].nex;
				}else{
					sum++;
					idd=s[idd].nex;
				}
			}
			printf("%d\n",sum);
			
		}else{
			int sum=0,idd=mp[ss1][ss2].id;
			while(idd!=0){
				string sp1,sp2;
				if(l+s[idd].st<0||l+s[idd].st+s[idd].s1.size()>q1.size()){
					idd=s[idd].nex;
				}else{
					for(int i=l+s[idd].st;i<l+s[idd].st+s[idd].s1.size();i++){
						sp1+=q1[i];
						sp2+=q2[i];
					}
					if(sp1==s[idd].s1&&sp2==s[idd].s2){
						sum++;
					}
					idd=s[idd].nex;
				}
				
			}
			printf("%d\n",sum);
		}
		
	}
	
	
	
	
	
} 
