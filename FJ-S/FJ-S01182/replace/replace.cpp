#include<bits/stdc++.h>
using namespace std;
int n,q,sen1[200005],sen2[200005],len1,len2,ans;
string s1[200005],s2[200005],l1,l2;
int check(int x){
	if(sen1[x]-sen2[x]!=len1-len2) return 0;
	int res=0;
	for(int i=0;i+sen1[x]<=len1;i++){
		if(i!=0){
			if(l2[i-1]!=l1[i-1]) return res;
		}
		bool fl=1;
		for(int j=0;j<sen1[x];j++){
			if(s1[x][j]!=l1[i+j]) {fl=0;break;}
		}
		if(!fl) continue;
		for(int j=0;j<sen2[x];j++){
			if(s2[x][j]!=l2[i+j]){
				fl=0;
				break;
			}
		}
		if(!fl) continue;
		for(int j1=sen1[x]+i,j2=sen2[x]+i;1;j1++,j2++){
			if((j1==len1&&j2<len2)||(j1<len1&&j2==len2)||(l1[j1]!=l2[j2])){
				fl=0;
				break;
			}
			if(j1>=len1&&j2>=len2) break;
		}
		if(!fl) continue;
		res++;
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sen1[i]=s1[i].size();
		sen2[i]=s2[i].size();
	}
	while(q--){
		ans=0;
		cin>>l1>>l2;
		len1=l1.size();len2=l2.size();
		for(int i=1;i<=n;i++){
			ans+=check(i);
		}
		cout<<ans<<"\n";
	}
}

