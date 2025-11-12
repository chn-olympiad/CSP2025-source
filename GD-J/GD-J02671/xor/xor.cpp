#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,k,a[N],f[N],s[N],sumn;
struct node{
	int l,r;
};
vector<node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i],sumn+=a[i]==k;
	int p=1,last=-1,cnt=0;
	for(int i=1;i<=n;i++){
		if(last!=a[i])	cnt=1,last=a[i];
		else	cnt++;
		if((cnt<=2||last==k)||k==0)	a[p]=a[i],s[p]=s[p-1]^a[p],p++;
	}n=p-1;
	
if(n<=10000){
//
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==k)	v.push_back({l,r});
		}
	}
	sort(v.begin(),v.end(),[](node& a,node& b){
		if(a.r==b.r)	return a.l>b.l;
		else	return a.r<b.r;
	});
	int r=-1,res=0;
	for(int i=0;i<v.size();i++){
		if(v[i].l>r)	res++,r=v[i].r;
	}cout<<res<<endl;
//
}else{
//		
	int maxn=0,idx=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=idx;j<=i;j++){
			if((s[i]^s[j-1])==k)	f[i]=f[i-1]+1;
		}if(f[i]>maxn){
			maxn=f[i],idx=i+1;
		}
	}cout<<max(f[n],sumn)<<endl;
//		
}

	fclose(stdin);
	fclose(stdout);
}/*
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
*/
