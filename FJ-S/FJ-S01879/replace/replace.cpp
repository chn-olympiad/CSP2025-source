#include<bits/stdc++.h>
using namespace std;
string s1[200001],s2[200001],question1[200001],question2[200001];
long long biaoji[400001],zong[200001],wj[400001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q,ans=0;
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		zong[i]=s1[i].size();
		for(long long j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				biaoji[2*i-1]=j;
			}
			if(s2[i][j]=='b'){
				biaoji[2*i]=j;
			}	
		}
	}
	for(long long i=1;i<=q;i++){
		ans=0;
		cin>>question1[i]>>question2[i];
		for(long long j=0;j<s1[i].size();j++){
			if(question1[i][j]=='b'){
				wj[2*i-1]=j;
			}
			if(question2[i][j]=='b'){
				wj[2*i]=j;
			}	
		}
		for(long long j=1;j<=n;j++){
			if(biaoji[2*j-1]-biaoji[2*j]==wj[2*i-1]-wj[2*i]&&question1[i].size()-wj[2*i-1]>=zong[j]-biaoji[2*j-1]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
