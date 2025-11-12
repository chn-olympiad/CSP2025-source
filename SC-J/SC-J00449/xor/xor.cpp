#include<bits/stdc++.h>
using namespace std;
int const N=5e5+1;
int a[N];
struct node{
	int l,r;
};
vector<node> vec;
int n,k,cnt=0;
bool operator < (node i,node j){
	if(i.l==j.l){
		return i.r<j.r;
	}
	return i.l<j.l;
}
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){//肯定优先选短的啊
			if((a[j]^a[i-1])==k){
				vec.push_back({i,j});
				break;
			}
		}
	}
	sort(vec.begin(),vec.end());
	int ed=0;
	for(int i=0;i<vec.size();i++){
		if(vec[i].l>ed){
			cnt++;
			ed=vec[i].r;
		}
	}
	print(cnt);
	return 0;
}