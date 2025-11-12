#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<string,string> ,vector<int> > f;
int L[210000],R[210000],lf[210000],rf[210000],cnt;
unsigned long long ha[5100000],hb[5100000],pown[5100000],base=131;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pown[0]=1;
	for(int i=1;i<=5e6;i++) pown[i]=pown[i-1]*base;
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str1,str2;lf[i]=rf[i]=-1;
		cin>>str1>>str2;
		for(int j=0;j<(int)str1.length();j++){
			if(str1[j]!=str2[j]){
				lf[i]=j;break;
			}
		}
		for(int j=(int)str1.length()-1;j>=0;j--){
			if(str1[j]!=str2[j]){
				rf[i]=j;break;
			}
		}
		L[i]=cnt+1;
		for(int j=0;j<(int)str1.length();j++,cnt++) ha[cnt+1]=ha[cnt]*base+(str2[j]-'a');
		R[i]=cnt;
		if(lf[i]==-1) continue;
		string dif1="",dif2="";
		for(int j=lf[i];j<=rf[i];j++) dif1+=str1[j],dif2+=str2[j];
		f[{dif1,dif2}].push_back(i);
	}
	while(q--){
		string str1,str2;int l,r;l=r=-1;
		cin>>str1>>str2;
		for(int j=0;j<(int)str1.length();j++){
			if(str1[j]!=str2[j]){
				l=j;break;
			}
		}
		for(int j=(int)str1.length()-1;j>=0;j--){
			if(str1[j]!=str2[j]){
				r=j;break;
			}
		}
		string dif1="",dif2="";
		for(int j=l;j<=r;j++) dif1+=str1[j],dif2+=str2[j];
		hb[0]=0;
		for(int j=0;j<(int)str1.length();j++) hb[j+1]=hb[j]*base+(str2[j]-'a');
		if(not f.count({dif1,dif2})){
			cout<<"0\n";
			continue;
		}
		vector<int> v=f[{dif1,dif2}];int ans=0;
		for(auto t:v){
			int tl=l-lf[t]+1,tr=tl+R[t]-L[t];
			if(tl<=0 or tr>(int)str1.length()) continue;
			//cout<<t<<" "<<tl<<" "<<tr<<'\n';
			if((hb[tr]-hb[tl-1]*pown[(tr-tl+1)])==(ha[R[t]]-ha[L[t]-1]*pown[(R[t]-L[t]+1)])) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
	return 0;
}
//Wo shi chang zhui yi guo qu...
//Wo gai zai na li ting liu ,wo wen wo zi ji.