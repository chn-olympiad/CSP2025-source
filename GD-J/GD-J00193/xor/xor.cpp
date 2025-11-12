#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
}a[N*2];
struct stu{
	int v,i;
	operator<(const stu&a){
		return v<a.v;
	}
}s2[N];
int s[N];
bool cmp(node a,node b){
	return a.r<b.r; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,t,m=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t;
		s[i]=s[i-1]^t;
		s2[i].v=s[i];
		s2[i].i=i;
	}
	sort(s2+1,s2+1+n); 
	for(int i=1;i<=n;i++){
		int t=s[i-1]^k;
		int id=lower_bound(s2+1,s2+1+n,stu({t,0}))-s2;
		while(id<=n&&s2[id].v==t){
			if(s2[id].i>=i)a[m].l=i,a[m++].r=s2[id].i;
			id++;
		}
	}
	if(m==0){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a,a+m,cmp);
	int st=a[0].r,cnt=1;
	for(int i=0;i<m;i++){ 
		if(a[i].l>st){
			st=a[i].r;
			cnt++;
		}
	}
	cout<<cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
//69
