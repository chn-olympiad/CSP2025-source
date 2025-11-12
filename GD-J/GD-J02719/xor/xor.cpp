#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+7,V=(1<<20);
int n,k,f[N],a[N];
int p[N],m[V+7];
multiset<int> s;

int main(){
	freopen("xor.in" ,"r",stdin );
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=(p[i-1]^a[i]);
	}
	for(int i=0;i<=V;i++){
		if(i==0) m[i]=0;
		else m[i]=-10000000; 
		s.insert(m[i]);
	}
	
	for(int i=1;i<=n;i++){
		int d=(p[i]^k);
		int l=m[d];
		s.erase(s.find(l));
		
		int x=(*s.rbegin());
		f[i]=max(x,l+1);
		
		s.insert(l);
		s.erase(s.find(m[p[i]]));
		m[p[i]]=max(m[p[i]],f[i]);
		s.insert(m[p[i]]);
	}
	printf("%d",f[n]);
	
	return 0;
}

