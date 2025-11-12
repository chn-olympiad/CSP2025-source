#include <bits/stdc++.h>
using namespace std;
//ÆÚÍû 100 

struct K{
	long long a,b,c;
}q[100100];

bool cmp(K k1,K k2){
	long long K1,K2;
	if(k1.a==0)       K1=abs(k1.b-k1.c);
	else if(k1.b==0)  K1=abs(k1.c-k1.a);
	else              K1=abs(k1.b-k1.a);
	if(k2.a==0)       K2=abs(k2.b-k2.c);
	else if(k2.b==0)  K2=abs(k2.c-k2.a);
	else              K2=abs(k2.b-k2.a);
	return K1>K2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	while(t--){
		long long n,ans=0;
		cin >> n;
		for(long long i=1;i<=n;i++){
			cin >> q[i].a >> q[i].b >> q[i].c;
			long long l=min(min(q[i].a,q[i].b),q[i].c);
			ans+=l;
			q[i].a-=l;
			q[i].b-=l;
			q[i].c-=l;
		}
		sort(q+1,q+1+n,cmp);
		long long A=0,B=0,C=0;
		for(long long i=1;i<=n;i++){
			K k=q[i];
			if(k.a==0)  
				if(k.b>k.c) 
					if(B>=n/2) C++,ans+=k.c;
					else      B++,ans+=k.b;
				else
					if(C>=n/2) B++,ans+=k.b;
					else	  C++,ans+=k.c;
			else if(k.b==0)  
				if(k.a>k.c) 
					if(A>=n/2) C++,ans+=k.c;
					else      A++,ans+=k.a;
				else
					if(C>=n/2) A++,ans+=k.a;
					else	  C++,ans+=k.c;
			
			else if(k.c==0)  
				if(k.b>k.a) 
					if(B>=n/2) A++,ans+=k.a;
					else      B++,ans+=k.b;
				else
					if(A>=n/2) B++,ans+=k.b;
					else	  A++,ans+=k.a;
		}
		cout << ans << "\n";
	}
	
	return 0;
}//1
/*
1
4
4 2 1 
3 2 4 
5 3 4 
3 5 1
*/
