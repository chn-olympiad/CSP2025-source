#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+5;	
int a[N];
struct rp{
	int a,b,c,k;
}d[N],s[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
	     int v=0;
	     int e,f,g=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].a>d[i].b){
				ans=d[i].a;
				s[i].k=e;
				}else {
					ans=d[i].b;
					s[i].k=f;
				}
				if(ans=d[i].a&&ans>d[i].c){
				a[i]=ans;
				s[i].k=e;
				}else if(ans=d[i].b&&ans<d[i].c){
					a[i]=d[i].c;
					s[i].k=g;
				}
					if(ans=d[i].b&&ans>d[i].c){
				a[i]=ans;
				s[i].k=f;
				}else if(ans=d[i].b&&ans<d[i].c){
					a[i]=d[i].c;
					s[i].k=g;
				}
			}
		for(int i=1;i<=n;i++){
			if(n<=3){
		if(s[i].k==e){
			v+=a[i];
        e++;		
}	else if(s[i].k==f){
			v+=a[i];
        f++;		
}
else if(s[i].k==g){
			v+=a[i];
        g++;
}
if(i==n&&e<=1&&f<=1&&g<=1){
	cout<<v;
}
}
}
}
fclose(stdin);
fclose(stdout);
return 0;
}

