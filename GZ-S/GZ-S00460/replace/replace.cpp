//GZ-s00460 ÄÏ°×ÖĞÑ§ ³Â²©Óî 
#include<bits/stdc++.h>
using namespace std;
struct an{
	string f,r;
};
an a[10001],p[10001];
int s,n,q;
int ans(int n){
	int s=0,b=1;
	for(int j=1;j<=q;j++){
		for(int k=1;k<=a[n].f.length();k++){
			if(a[n].f[k]!=p[j].f[1]&&a[n].f[k]!=a[n].r[k]) break;
				if(a[n].f[k]==p[j].f[1]&&a[n].r==p[j].r){
					for(int l=1;l<=p[j].f.length();l++){
					    if(a[n].f[k+l-1]!=p[j].f[l]||a[n].r[k+l-1]!=p[j].r[l]){
					    	b=0;
					    	break;
						}
	   			}
				    for(int i=k+p[j].f.length()+1;i<=a[n].f.length();i++){
					if(a[n].f[i]!=a[n].r[i]){
						b=0;
						break;
					} 
				}
				if(b==1) s++;
				}
			}
		}
		cout<<s<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++){
	cin>>p[i].f>>p[i].r;
}
for(int i=1;i<=q;i++){
	cin>>a[i].f>>a[i].r; 
}
for(int i=1;i<=q;i++){
	cout<<ans(n);
}
      return 0; 
}
