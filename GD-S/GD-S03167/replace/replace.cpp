#include<bits/stdc++.h>
#define p 131
#define int unsigned long long
using namespace std;

constexpr int N=2e5+5,L=5e6+5;
int n,q;
int a[N],b[N],P[L],t1[L],t2[L];
string s1,s2;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	P[0]=1;
	for(int i=1;i<=5e6;i++) P[i]=P[i-1]*p;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s1=' '+s1;
		s2=' '+s2;
		for(int j=1;j<s1.size();j++){
			a[i]=a[i]*p+s1[j];
			b[i]=b[i]*p+s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		s1=' '+s1;
		s2=' '+s2;
		int len=s1.size();
		int beg=0,las=len-1;
		for(int j=1;j<len;j++){
			t1[j]=t1[j-1]*p+s1[j];
			t2[j]=t2[j-1]*p+s2[j];
			if(t1[j]!=t2[j]&&!beg) beg=j;
		}
		for(int j=len-1;j>=1;j--){
			if(t1[len]-t1[j-1]*P[len-j+1]!=t2[len]-t2[j-1]*P[len-j+1]){
				las=j;
				break;
			}
		}
		//cout<<beg<<" "<<las<<endl;
		if(beg==0) cout<<0<<endl;
		else{
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(t1[las]-t1[beg-1]*P[las-beg+1]==a[j]&&t2[las]-t2[beg-1]*P[las-beg+1]==b[j]) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
}
