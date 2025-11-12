#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,q,k1,k2;
string s1,s2,s3,s4,a[200005][3];
bool check(int i){
	if(a[i][0].size()<s3.size()) return false;
	int k3=0,k4=a[i][0].size()-1,l=a[i][0].size();
	while(a[i][0][k3]==a[i][1][k3]&&k3<l) k3++;
	while(a[i][0][k4]==a[i][1][k4]&&k4>=0) k4--;
	//cout<<s1.substr(k1-k3,k2-k4-k1+k3+l)<<' '<<s2.substr(k1-k3,k2-k4-k1+k3+l);
	if(k3<=k1&&k4-k3+1==k2-k1+1&&a[i][0]==s1.substr(k1-k3,k2-k4-k1+k3+l)&&a[i][1]==s2.substr(k1-k3,k2-k4-k1+k3+l)) return true;
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
	for(int i=1;i<=q;i++) {
		cin>>s1>>s2;
		int l,ans=0;
		if(s1.size()!=s2.size()) {printf("0\n");continue;}
		l=s1.size();
		k1=0;
		k2=l-1;
		while(s1[k1]==s2[k1]&&k1<l) k1++;
		while(s1[k2]==s2[k2]&&k2>=0) k2--;
		s3=s1.substr(k1,k2-k1+1);
		s4=s2.substr(k1,k2-k1+1);
		for(int i=1;i<=n;i++) if(check(i)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
