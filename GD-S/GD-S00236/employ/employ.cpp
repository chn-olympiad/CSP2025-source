#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m;
int len=0;
int leng=0;
int leng1=0;
int len1=0;
struct node{
	char nan;
	int c;
	int x=0;
}a[520];
bool cmp(node a,node b){
    return a.c<b.c;
}
bool cmp2(node a,node b){
	return a.x>b.x;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].nan;
		if(a[i].nan=='1') leng1++;
	}
	for(int i=1;i<=n;i++) cin>>a[i].c;
	sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
    	if(leng+1>m) break;
    	if(len>a[i].c){
    		len++;
			continue;
		}
    	if(a[i].nan=='1'&&leng+1<=m){
    		leng++;
    		a[i].x=1;
		}
		else len++;
	}
	if(leng<m){
		leng+=(m-leng);
	}
	len=n-leng;
	sort(a+1,a+n+1,cmp2);
	int ans=1;
	int q=leng;
	for(int i=1;i<=len;i++) ans*=q,q--;
	int ans2=1;
	for(int i=1;i<=len;i++) ans2*=i;
	int x1=ans/ans2;
	cout<<x1%998244353<<endl;
	return 0;
} 

