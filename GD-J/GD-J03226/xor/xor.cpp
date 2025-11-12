#include<bits/stdc++.h>
using namespace std;
int n,k,r,R[500000],t,last_,maxx,T[500000],c;
struct S{
	int s,e;
}N[500000];
int f(int a,int b){
	bool A,B;
	int C=0,D=1;
	for(int i=0;i<=31;i++){
		if(a%2==0)A=0;
		else A=1;
		if(b%2==0)B=0;
		else B=1;
		if(A!=B)C+=D;
		a/=2,b/=2,D*=2;
	}
	return C;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>R[i];
		r=R[i],c=0;
		for(int j=i-1;j>=0;j--){
			if(r==k)T[c]=j,c++;
			r=f(r,R[j]);
		}
		for(c--;c>=0;c--)N[t].s=T[c]+1,N[t].e=i,t++;
	}
	for(int i=0;i<t;i++){
		if(N[i].s>last_)maxx++,last_=N[i].e;
	}
	cout<<maxx;
	return 0;
}
