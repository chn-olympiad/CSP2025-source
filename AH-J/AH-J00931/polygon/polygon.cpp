#include<bits/stdc++.h>
using namespace std;
struct str{
	multiset<int>ms;
	long long maxn=-1,ans=0;
};
set<multiset<int> >s;
queue<str>q;
long long n,a[5005],ansq=0;
long long mood=998244353;
int bfs(){
	while(!q.empty()){
		str b2=q.front();
		q.pop();
		if(b2.ms.size()>=3&&b2.ans>2*b2.maxn){
			ansq=(ansq+1)%mood;
		}
		for(int i=0;i<n;i++){
			if(b2.ms.find(i)==b2.ms.end()){
				str b3=b2;
				b3.ms.insert(i);
				if(s.find(b3.ms)==s.end()){
					b3.maxn=max(a[i],b3.maxn);
					b3.ans=b3.ans+a[i];
					s.insert(b3.ms);
					q.push(b3);
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		str b1;
		b1.ms.insert(i);
		b1.ans=a[i];
		b1.maxn=a[i];
		s.insert(b1.ms);
		q.push(b1);
	}
	bfs();
	printf("%lld",ansq%mood);
	return 0;
}
