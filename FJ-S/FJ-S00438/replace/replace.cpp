//1=C 4/4
//		  .							~~~~			  .		  .			    ~~~~~
// 0 35 6 1 | 7.5 3.1 | 1.6 65 32 | 23 3 - - | 0 35 6 1 | 7.3 1.3 | 2.6 65 32 | 11 1 - - |
//																				 ~~~
// ¡ª¡ª¡¶Ê±¼äÖóÓê¡· Óô¿ÉÎ¨
#include <bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
string s1[200005],s2[200005],n1[200005],n2[200005];
int I[200005],J[200005],vis[200005];
vector<int> ha1[244355],ha2[344355];
int fa1[244355],fa2[344355],fa3[244355],fa4[344355];
#define M1 244353
#define M2 344353
int hash1(string s){
	int k=s.size(),ans=0;
	for(int i=0;i<k;i++)ans=((long long)(ans)*26+s[i]-'a')%M1;
	return ans;
}
int hash2(string s){
	int k=s.size(),ans=0;
	for(int i=0;i<k;i++)ans=((long long)(ans)*26+s[i]-'a')%M2;
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,h1,h2,h3,h4,I1,J1,check,ans,Si;//silicon
	string t1,t2,na,nb;
	//scanf("%d%d",&n,&q);
	cin>>n>>q;
	for(int harris=1;harris<=n;harris++){
		cin>>s1[harris]>>s2[harris];
		Si=s1[harris].size();
		I[harris]=0,J[harris]=Si-1;
		while(s1[harris][I[harris]]==s2[harris][I[harris]])I[harris]++;
		while(s1[harris][J[harris]]==s2[harris][J[harris]])J[harris]--;
		n1[harris]=n2[harris]="";
		for(int biden=I[harris];biden<=J[harris];biden++){
			n1[harris]=n1[harris]+s1[harris][biden];
			n2[harris]=n2[harris]+s2[harris][biden];
		}
		//cout<<n1[harris]<<","<<I[harris]<<'-'<<n2[harris]<<","<<J[harris]<<endl;
		ha1[hash1(n1[harris])].push_back(harris);
		ha2[hash2(n1[harris])].push_back(harris);
		fa1[hash1(n1[harris])]=harris;
		fa2[hash2(n1[harris])]=harris;
		fa3[hash1(n2[harris])]=harris;
		fa4[hash2(n2[harris])]=harris;
		J[harris]=Si-J[harris]-1;
	}
	for(int harris=1;harris<=q;harris++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0"<<endl;
			continue;
		}
		Si=t1.size();
		i=0,j=Si-1;
		while(t1[i]==t2[i])i++;
		while(t1[j]==t2[j])j--;
		na=nb="";
		for(int biden=i;biden<=j;biden++){
			na=na+t1[biden];
			nb=nb+t2[biden];
		}
		//cout<<na<<" "<<nb<<endl;
		h1=hash1(na),h2=hash2(na),h3=hash1(nb),h4=hash2(nb);
		if(fa1[h1]&&fa2[h2]&&fa3[h3]==fa1[h1]&&fa4[h4]==fa2[h2]){
			for(int ii:ha1[h1])vis[ii]=harris;
			ans=0;
			for(int ii:ha2[h2]){
				if(vis[ii]==harris){
					if(i-I[ii]>=0&&j+J[ii]<Si){
						check=1;
						I1=i-I[ii],J1=j+J[ii];
						for(int jj=I1;jj<=J1;jj++){
							if(t1[jj]!=s1[ii][jj-I1]){
								check=0;
								break;
							}
						}
						if(check==1)ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		else cout<<"0"<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
