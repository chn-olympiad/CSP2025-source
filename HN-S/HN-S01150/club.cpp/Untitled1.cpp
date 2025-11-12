#include<bits/stdc++.h>
using namespace std;
struct sb{
	long long aa;
	long long b;
	long long c;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	for(int q=1;q<=t;q++){
		long long n,s=0;
		bool a1=0,b1=0,c1=0;
		cin>>n;
		sb a[n];
		long long ar=0,br=0,cr=0,x=0,y=0,z=0;
		for(int i=0;i<n;i++){
			cin>>a[i].aa>>a[i].b>>a[i].c;
			if(max(a[i].aa,max(a[i].b,a[i].c))==a[i].aa&&a1==0){
				ar++;
				if(ar>n/2){
					a1=1;
					ar--;
				}else{
					s+=a[i].aa;
				}
			}else if(a1==1){
				a[i].aa=0;
			}
			if(max(a[i].aa,max(a[i].b,a[i].c))==a[i].b&&b1==0){
				br++;
				if(br>n/2){
					b1=1;
					br--;
				}else{
					s+=a[i].b;
				}
			}else if(b1==1){
				a[i].b=0;
			}
			if(max(a[i].aa,max(a[i].b,a[i].c))==a[i].c&&c1==0){
				cr++;
				if(cr>n/2){
					c1=1;
					cr--;
				}else{
					s+=a[i].c;
				}
			}else if(c1==1){
				a[i].c=0;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
