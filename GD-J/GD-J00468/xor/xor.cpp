#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int a[maxn];
struct line{int l,r;};
vector<line>ans;
bool cmp(line a,line b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	for(int i=1;i<=n;i++){
		int t=read();
		a[i]=a[i-1]^t;
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x=a[j]^a[i];
			if(x==k)ans.push_back(line{i+1,j});
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int m=ans.size();
	int prr=-1;
	int res=0;
	for(int i=0;i<m;i++){
		if(ans[i].l<=prr)continue;
		prr=ans[i].r;
		res++;
	}
	cout<<res;
	return 0;
}  
