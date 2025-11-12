#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> inline void read(T &x){
	x=0;
	T w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=w;
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),x=(~x)+1;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const ll M=5e6+10,N=2e5+10;
char c[M],c1[M];
struct data{
	string a,b;
}d[N];
ll n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);	
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		d[i].a=c+1;
		scanf("%s",c+1);
		d[i].b=c+1;
	}
	while(q--){
		scanf("%s",c+1),scanf("%s",c1+1);
		string x=c+1,y=c1+1;
		ll n1=strlen(c+1),n2=strlen(c1+1);
		if(n1!=n2){
			puts("0");
			continue;
		}
		ll l=1,r=n1;
		while(c[l]==c1[l]) l++;
		while(c[r]==c1[r]) r--;
		if(l>r){
			puts("0");
			continue;
		}
//		cout<<"step\n";
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(d[i].a.size()>n1||d[i].a.size()<r-l+1) continue;
			string suc=x,pre="",mid="";
			for(int j=0;j<n1;j++){
				mid=mid+x[j];
				suc.erase(0,1);
				if(mid.size()>d[i].a.size()) pre=pre+mid[0],mid.erase(0,1);
				if(mid.size()==d[i].a.size()){
					if(mid==d[i].a){
						string t=pre+d[i].b;
						t=t+suc;
						if(t==y){
							ans++;
//							break;
						}
					}
				}
			}
		}
		write(ans);
		putchar('\n');
//		cout<<l<<' '<<r<<"\n";
	}
	return 0;
}

