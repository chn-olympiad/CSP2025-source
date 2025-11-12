#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,e; 
}m[500010]; 
int n,a[500010],k,s[500010];
bool cmp(node x,node y){
	if(x.s<y.s)
		return true;
	if(x.s==y.s && x.e) 
	return false; 
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	int oka=1,okb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			oka=0;
		if(a[i]>1)
			okb=0;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++)
		s[i]=a[i]^s[i-1];
	if(k==0 && oka){
		printf("%d",n/2);
		return 0;
	}
	if(k<=1 && okb){
		if(k==0){
			int l=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)
					l++; 
				else if(a[i]==a[i+1])
					l++,i++; 
			} 
			cout<<l; 
		} else{
			int l=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) l++; 
				else if((a[i]==1 && a[i+1]==0) || (a[i]==0 && a[i+1]==1))
					l++,i++; 
			} 
			cout<<l ;
		} 
		return 0; 
	}
	if(n<=1010) {
		int len=0; 
		for(int i=1;i<=n;i++) {
			for(int j=i,l=0;j<=n && l==0;j++){
				int a;
				if(i!=1) 
					a=s[j]^s[i-1];
				else{
					a=s[j]; 
				} 
				if(a==k){
					l=1; 
					m[++len].s=i;
					m[len].e=j; 
				}	
			} 
		}
		int en=m[1].e,ans=1;
		for(int i=2;i<=len;i++){
			if(m[i].s<=en){
				if(m[i].e<en) en=m[i].e; 
			} else{
				++ans;
				en=m[i].e;
			} 
		} 
		cout<<ans; 
	}
}
/*
1 xor 0=1
0 xor 0=0
1 xor 1=0

1 0 10 01 01 010 
1 1 11 10 11 1
2 0
1 1
*/
