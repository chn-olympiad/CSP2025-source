#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,mx[200020];
struct nw{
	int v,d;
}a[200020],b[200020],c[200020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		ll fg=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v>>b[i].v>>c[i].v;
			fg+=b[i].v+c[i].v;
			mx[i]=max(a[i].v,max(b[i].v,c[i].v));
			a[i].d = b[i].d = c[i].d = i;
		}
		int s=0;
		if(!fg){
			cout<<n/2<<endl;
		}
		else if(n==2){
			for(int i=1;i<n;i++){
				for(int j=i;j<=n;j++){
					s=max(a[i].v + b[j].v ,a[i].v + c[j].v );
					s=max(s , b[i].v + a[j].v);
					s=max(s , b[i].v + c[j].v);
					s=max(s , c[i].v + a[j].v);
					s=max(s , c[i].v + b[j].v);
				}
			}
			cout<<s<<endl;
		}
		else {
			for(int i=n;i>=n/2;i--)s+=mx[i];
			cout<<s<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
