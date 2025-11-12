#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int L,R;
}d[N];
int n,k,a[N],b[N],c,cnt=0,t=0;
int fx(int A,int B){
	string AA,BB;
	while(A){
		AA+=char(A%2+'0');
		A/=2;
	}
	while(B){
		BB+=char(B%2+'0');
		B/=2;
	}
	int Aa=AA.size(),Bb=BB.size();
	if(Aa<Bb){
		string C;
		for(int i=1;i<=Bb-Aa;i++)C+='0';
		AA=AA+C;
	}
	if(Aa>Bb){
		string C;
		for(int i=1;i<=Aa-Bb;i++)C+='0';
		BB=BB+C;
	}
	Aa=AA.size();
	string C;
	for(int i=0;i<Aa;i++){
		if(AA[i]=='0'){
			C+=BB[i];
		}else{
			if(BB[i]=='0')C+='1';
			else C+='0';
		}
	}
	int Cc=C.size(),cnt=1,sum=0;
	for(int i=0;i<Cc;i++){
		sum+=cnt*(C[i]-'0');
		cnt*=2;
    }
    return sum;
}
bool cmp(node A,node B){
	if(A.R==B.R)return A.L<B.L;
	return A.R<B.R;
}
int main () {
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>k;
   bool F=1;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
	   if(a[i]!=1&&a[i]!=0)F=0;
   }
   if(F){
	   if(k>1){
		   cout<<0;
	   }else{
		   int ans=0;
		   if(k==1){
			   for(int i=1;i<=n;i++){
				   if(a[i]==1)ans++;
			   }
		   }else{
			   for(int i=1;i<=n;i++){
				   if(a[i]==0)ans++;
				   else{
					   if(a[i]==1&&a[i+1]==1){
						   ans++;
						   i++;
					   }
				   }
			   }
		   }
		   cout<<ans;
	   }
	   return 0;
   }
   for(int i=1;i<=n;i++){
	   b[i]=b[i-1]^a[i];
   }
   int t=0;
   for(int r=1;r<=n;r++){
	   for(int l=0;l<r;l++){
		   if(fx(b[r],b[l])==k){
			   d[++t].L=l+1;
			   d[t].R=r;
		   }
	   }
   }
   sort(d+1,d+1+t,cmp);
   if(t>0)cnt++;
   int idx=1;
   for(int i=2;i<=t;i++){
	   if(d[i].L>d[idx].R){
		   cnt++;
		   idx=i;
	   }
   }
   cout<<cnt;
   return 0;
}
