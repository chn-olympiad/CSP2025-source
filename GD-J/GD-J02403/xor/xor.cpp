#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,k,a[100100],b[100100],ans,o=1;
bool v[100100];
struct r{
	int s,e;
};
r w[100100];
bool cmp(r a,r b){
	if(a.e!=b.e) return a.e<b.e;
	return a.s>b.s;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((b[i]^b[j-1])==k){
				w[o].s=j;
				w[o].e=i;
				o++;
			}
		}
	}
	sort(w+1,w+1+o,cmp);
	for(int i=1,l=0;i<=o;i++){
		if(w[i].s>l){
			l=w[i].e;
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

