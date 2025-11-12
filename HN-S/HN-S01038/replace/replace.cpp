#include<bits/stdc++.h>
using namespace std;
struct t1{
	string a,b;
}a1[400010];
long long a2[400010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k;
	string l,m,n;
	cin>>a>>b;
	for(i=1;i<=a;i++){
		cin>>a1[i].a>>a1[i].b;
		a2[i]=a1[i].a.length();
	}
	for(i=1;i<=b;i++){
		cin>>l>>m;
		c=l.length();
		if(c!=m.length()){
			cout<<0<<endl;
			continue;
		}
		f=0;
		for(j=0;j<c;j++){
			for(k=1;k<=a;k++){
				g=1;
				n=l;
				for(h=0;h<a2[k];h++){
					if(a1[k].a[h]!=l[h+j]||a1[k].b[h]!=m[h+j]){
						g=0;
						break;
					}
					n[h+j]=a1[k].b[h];
				}
				if(n==m){
					if(g==1){
					}
					f+=g;
				}
			}
		}
		cout<<f<<endl;
	}
	return 0;
}
