#include<bits/stdc++.h>
using namespace std;
struct s{
	int s1,s2,s3;
	int a1,a2;
}a[100010];
int b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,f=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s1>a[i].s2){
				if(a[i].s1>a[i].s3){
					a[i].a1=1;
					a[i].a2=a[i].s1;
				}
				else{
					a[i].a1=3;
					a[i].a2=a[i].s3;
				}
			}
			else{
				if(a[i].s2>a[i].s3){
					a[i].a1=2;
					a[i].a2=a[i].s2;
				}
				else{
					a[i].a1=3;
					a[i].a2=a[i].s3;
				}
				
			}
		}
		for(int i=0;i<n;i++){
			b[i]=a[i].a2;
		}
		sort(b,b+n);
		for(int i=0;i<n/2;i++){
			f+=b[i];
		}
		cout<<f<<endl;
	}
	return 0;
	//Ren5Jie4Di4Ling5%
}
