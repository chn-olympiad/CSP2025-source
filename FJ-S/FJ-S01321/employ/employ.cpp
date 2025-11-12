#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
bool d[505];
struct C{
	int ii,num;
};
C c[505];
bool cmp(C x, C y){
	return x.num < y.num;
}
void f(int xi, int bad, int k, int nn){
	if(nn == n){
		if(k >= m) ans++;
		return ;
	}
	int x = c[xi].ii;
	int stand = c[xi].num;
	if(bad >= stand){
		for(int i=1; i <= n; i++){
			if(i == x || d[i]) continue;
			d[i] = 1;
			f(i,bad+1,k,nn+1);
			d[i]=0;
		}
	}else{
		for(int i=1; i <= n; i++){
			if(i == xi || d[i]) continue;
			d[i] = 1;
			f(i,bad+1,k+1,nn+1);
			d[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i <= n; i++){
		cin>>c[i].num;
		c[i].ii = i;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1; i <= n; i++) f(i,0,1,1);
	cout<<ans;
	return 0;
}
