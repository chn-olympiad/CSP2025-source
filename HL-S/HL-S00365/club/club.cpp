#include<bits/stdc++.h>
using namespace std;
struct f{
	int a,b,c;
};
bool cmp(f a,f b){
	return a.a<b.a;
	if(a.a==b.a) return a.b>b.b;
	else if(a.b==b.b) return a.c>b.c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	f a[100005];
	while(t!=0){
		int n;
		cin>>n;
		long long he=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		int a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b && a[i].a>a[i].c){
				if(a1>=n/2){
					if(a[i].b>a[i].c){
						if(a2>=n/2){
							a3++;
							he+=a[i].c;
						}
						else{
							a2++;
							he+=a[i].b;
						}
					}
				}
				else{
					a1++;
				    he+=a[i].a;
				}
			}
			if(a[i].b>a[i].a && a[i].b>a[i].c){
				if(a2>=n/2){
					if(a[i].a>a[i].c){
						if(a1>=n/2){
							a3++;
						    he+=a[i].c;
						}
						else{
							a1++;
							he+=a[i].a;
						}
					}
				}
				else{
					a2++;
				    he+=a[i].b;
				}
				
			}
			if(a[i].c>a[i].b && a[i].c>a[i].a){
				if(a3>=n/2){
					if(a[i].b>a[i].a){
						if(a2>=n/2){
							a1++;
							he+=a[i].a;
						}
						else {
							a2++;
						    he+=a[i].b;
						}
					}
				}
				else{
					a3++;
					he+=a[i].c;
				}
			}
		}
		cout<<he<<endl;
		t--;
	}
	return 0;
}
