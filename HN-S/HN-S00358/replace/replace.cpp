#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[100005],s3,s4;
int ans[200005];
int n,q,i,j;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(i=0;i<q;i++){
		cin>>s3>>s4;
		if(s3.size()!=s4.size()){
			ans[i]=0;
		}
		else{
			ans[i]=1;
		}
	}
	for(i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
