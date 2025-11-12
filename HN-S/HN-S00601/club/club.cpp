#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct sss{
	long long a,b,c;
}a[N];
long long c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long sum=0;
		int n;
		cin>>n;
		int s=0,h=0,g=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		for(int i=1;i<=n;i++){
			int m=a[i].a-c[1],n=a[i].b-c[1+n/2],k=a[i].c-c[1+n];
			bool o=1;
			if(s>=1){
				sort(c+1,c+1+s);
			} 
			if(max(m,max(n,k))==m){
				if(s<n/2){
					s++;
					c[s]=a[i].a;
					o=0;
				}else{
					if(a[i].a>c[1]){
						c[1]=a[i].a;
					}
				}
			}
			if(h>=1){
				sort(c+n/2+1,c+n/2+h);
			} 
			if(max(m,max(n,k))==n||(o&&max(n,k)==n)){
				if(h<n/2){
					h++;
					c[h+n/2]=a[i].b;
					o=0;
				}else{
					if(a[i].b>c[1+n/2]){
						c[1+n/2]=a[i].b;
					}
				}
			}
			if(g>=1){
				sort(c+n+1,c+n+g);
			} 
			if(max(m,max(n,k))==k||o){
				if(h<n/2){
					h++;
					c[g+n]=a[i].c;
					o=0;
				}else{
					if(a[i].c>c[1+n]){
						c[1+n]=a[i].c;
					}
				}
			}
		}
		for(int i=1;i<=s;i++){
			sum+=c[i];
		}
		for(int i=n/2+1;i<=n+h;i++){
			sum+=c[i];
		}
		for(int i=1+n;i<=n+g;i++){
			sum+=c[i];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
