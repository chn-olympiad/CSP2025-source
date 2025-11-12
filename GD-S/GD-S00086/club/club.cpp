#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
struct str{
	int a1,a2,a3;
	int m1,m2;
};
bool cmp(str a,str b){
	return min(a.m1,a.m2)<min(b.m1,b.m2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,h1=0,h2=0,h3=0;
		long long h=0;
		str a[N]={};
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].m1=a[i].a1-a[i].a2;
			a[i].m2=a[i].a1-a[i].a3;
			h+=a[i].a1;
		}
		h1=n;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2){
				if(a[i].m1<a[i].m2){
					h1--;
					h-=a[i].m1;
					h2++;
				}else{
					h1--;
					h-=a[i].m2;
					h3++;
				}
			}else{
				if(a[i].m1<a[i].m2){
					if(a[i].m1<0&&h2<n/2){
						h1--;
						h-=a[i].m1;
						h2++;
					}
				}else{
					if(a[i].m2<0&&h3<n/2){
						h1--;
						h-=a[i].m2;
						h3++;
					}
				}
			}
		}
		cout<<h<<endl;
	}
	return 0;
} 
