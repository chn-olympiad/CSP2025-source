#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int Maxn=2e5+10;

int n,q;
string s1[Maxn],s2[Maxn],t1[Maxn],t2[Maxn];

int main() {
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) {
		int sum=0;
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size()) {
			printf("0\n");
			continue;
		}
		int lent=t1[i].size();
		for(int j=1;j<=n;j++) {
			int l=0,lens=s1[j].size();
			while(l<=lent-lens) {
				int tmp=t1[i].find(s1[j],l);
				if(tmp!=-1) {
					string tp=t1[i].substr(0,tmp)+s2[j]+t1[i].substr(tmp+lens,lent-tmp-lens);
//					cout<<tp<<endl;
					if(tp==t2[i])sum++;
					l=tmp+lens;	
				} else break;
			}
		}
		printf("%d\n",sum);
	}
	
	/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


	*/
	return 0;
}
