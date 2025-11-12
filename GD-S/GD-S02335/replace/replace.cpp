//
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;

string s1[MAXN],s2[MAXN];
int a1[MAXN],a2[MAXN],dis[MAXN],tim[MAXN];
queue<int> q; 

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,qq;
	cin >> n >> qq;
	for (int i=1;i<=n;i++) cin >> s1[i] >> s2[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<s1[i].size();j++)
			if (s1[j]!=s1[j-1]) a1[i]=j;
		for (int j=1;j<s2[i].size();j++)
			if (s2[j]!=s2[j-1]) a2[i]=j;
	}
	while (qq--){
		string a,b;
		cin >> a >> b;
		int tmp1=0,tmp2=0;
		for (int j=1;j<a.size();j++)
			if (a[j]!=a[j-1]) tmp1=j;
		for (int j=1;j<b.size();j++)
			if (b[j]!=b[j-1]) tmp2=j;
		q.push(tmp1);
		dis[tmp1]=1;
		tim[tmp1]=qq;
		while (q.size()){
			int t=q.front();
			q.pop();
			for (int i=1;i<=n;i++){
				if (t>=a1[i] and (t+s1[i].size()-a1[i]<=a.size()) and (dis[t-a1[i]+a2[i]]>dis[t]+1 or tim[t-a1[i]+a2[i]]>qq)){
					dis[t-a1[i]+a2[i]]=dis[t]+1;
					tim[t-a1[i]+a2[i]]=qq;
					q.push(t-a1[i]+a2[i]);
				} 
			}
		}
//		if (tim[tmp2]==qq) 
			printf("%d\n",dis[tmp2]);
//		else printf("0\n");
	}

	return 0;
}

