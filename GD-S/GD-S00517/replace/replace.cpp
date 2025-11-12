#include<bits/stdc++.h>
#define fo(i,x,y) for(register int i=(x);i<=(y);++i)
#define ll unsigned long long
using namespace std;
const int N=200001;
int l[N];
string a[N],b[N],x,y,z;
ll c[N];
void print(const ll a){
	if(a>9)
		print(a/10);
	putchar(a%10|48);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	fo(i,1,n){
		cin>>a[i]>>b[i];
		l[i]=a[i].size()-1;
		fo(j,0,l[i])
			c[i]=c[i]*97+a[i][j]-'a'+1;
	}
	while(m--){
		cin>>x>>y;
		const int w=x.size()-1;
		ll u=0;
		fo(i,1,n){
			ll s=0,t=1;
			fo(j,0,l[i])
				t*=97;
			fo(j,0,w){
				s=s*97+x[j]-'a'+1;
				if(j>l[i])
					s-=(x[j-l[i]-1]-'a'+1)*t;
				if(j>=l[i]&&s==c[i]){
					z="";
					fo(k,0,w)
						if(k>j-l[i]-1&&k<=j){
							z+=b[i];
							k=j;
						}
						else
							z+=x[k];
					if(z==y)
						++u;
				}
			}
		}
		print(u);
		putchar('\n');
	}
	return 0;
}
