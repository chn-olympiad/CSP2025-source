#include<bits/stdc++.h>
using namespace std;
int t,n;
int k[5],A[4];
long long sum;
struct node{
	int a,b,c,d,e,f,g;
}s[100010];
bool cmp(node x,node y){
	return x.d-x.e>y.d-y.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(A,0,sizeof(A));
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			k[1]=s[i].a;k[2]=s[i].b;k[3]=s[i].c;
			sort(k+1,k+3+1);
			s[i].d=k[3];s[i].e=k[2];
			if(s[i].d==s[i].a)s[i].f=1;
			if(s[i].d==s[i].b)s[i].f=2;
			if(s[i].d==s[i].c)s[i].f=3;
			if(s[i].e==s[i].a)s[i].g=1;
			if(s[i].e==s[i].b)s[i].g=2;
			if(s[i].e==s[i].c)s[i].g=3;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			int x=s[i].f,y=s[i].g;
			if(A[x]==n/2){
				A[y]++;
				sum+=s[i].e;
			}
			else {
				A[x]++;
				sum+=s[i].d;
			}	
		}
		cout<<sum<<endl;
	}
	return 0;
}
