#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[8005],s2[8005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int ls1=s1[i].size(),lt1=t1.size();	
			for(int j=0;j<=lt1-ls1;j++){
				int k=j+ls1-1,jk=0;
				string linshi="",t11=t1;                                   
				for(int l=j;l<=k;l++)linshi+=t1[l],t11[l]=s2[i][jk++];	
				if(linshi==s1[i]&&t11==t2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	while(1);
	return 0;
}
