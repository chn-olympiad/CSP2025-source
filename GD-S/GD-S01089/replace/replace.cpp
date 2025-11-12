#include<iostream>
using namespace std;
long long n,q;
string s[20005][2];
string cut(string s,long long l,long long r){
	if (l>r)
		return "";
	string ans="";
	for (long long i=l;i<=r;i++)
		ans+=s[i];
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for (long long i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while (q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if (t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		for (long long i=0;i<t1.size();i++)
			for (long long j=0;j<=i;j++){
				string t3=cut(t1,j,i),t4=cut(t2,j,i),t5=cut(t1,0,j-1),t6=cut(t2,0,j-1),t7=cut(t1,i+1,t1.size()-1),t8=cut(t2,i+1,t2.size()-1);
				for (long long k=1;k<=n;k++)
					if (s[k][0]==t3&&s[k][1]==t4&&t5==t6&&t7==t8)
						ans++;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
