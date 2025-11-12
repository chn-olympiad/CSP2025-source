#include<iostream>
#include<algorithm>
#define ull unsigned long long
using namespace std;
const int N=2e5+7,base=131;
int n,q;
pair<ull,ull> s[N];
ull hashx(string s,int l,int r){
	ull res=0;
	for(int i=l;i<=r;i++) res=res*base+s[i];
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		if(a==b) continue;
		int l=0,r=a.length()-1;
		while(l<a.length()&&a[l]==b[l]) l++;
		while(r>=0&&a[r]==b[r]) r--;
		s[i]=make_pair(hashx(a,l,r),hashx(b,l,r)); 
	}
	for(int i=1;i<=q;i++){
		string a,b;pair<ull,ull> h;
		cin>>a>>b;
		if(a.length()!=b.length()){
			printf("0\n");
			continue;
		}
		int l=0,r=a.length()-1,L=1,R=n;
		while(l<a.length()&&a[l]==b[l]) l++;
		while(r>=0&&a[r]==b[r]) r--;
		h=make_pair(hashx(a,l,r),hashx(b,l,r));
		L=lower_bound(s+1,s+n+1,h)-s,R=upper_bound(s+1,s+n+1,h)-s;
		printf("%d\n",R-L);
	}
	return 0; 
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
