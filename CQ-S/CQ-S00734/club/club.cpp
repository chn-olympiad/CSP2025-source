#include<bits/stdc++.h>
using namespace std;
struct opo{
	int a,b,c;
}a[100005],f[100005];
int ans=0;
bool cmp(opo a,opo b){
	return max(a.b,a.c)>max(b.b,b.c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			f[i].b=a[i].b-a[i].a;
			f[i].c=a[i].c-a[i].a;
			ans+=a[i].a;
		}
		int a1=n,a2=0,a3=0;
		int cnt=0;
		sort(f+1,f+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2){
				if(f[i].b>f[i].c){
					ans+=f[i].b;
					a1--;
					a2++;
				}else if(f[i].b<f[i].c){
					ans+=f[i].c;
					a1--;
					a3++;
				}else{
					if(a2<a3){
						a2++;
						ans+=f[i].b;
						a1--;
					}else{
						a3++;
						ans+=f[i].c;
						a1--;
					}
				}
			}else{
				if(f[i].b>f[i].c){
					if(f[i].b>0){
						if(a2<n/2){
							a2++;
							a1--;
							ans+=f[i].b;
						}
					}
				}else if(f[i].c>f[i].b){
					if(f[i].c>0){
						if(a3<n/2){
							a3++;
							a1--;
							ans+=f[i].c;
						}
					}
				}else{
					if(f[i].c>0){
						if(a2<a3&&a2<n/2){
							a2++;
							a1--;
							ans+=f[i].b;
						}else if(a3<n/2){
							a3++;
							a1--;
							ans+=f[i].c;
						}
					}
				}
				
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
