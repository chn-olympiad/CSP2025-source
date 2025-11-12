#include<bits/stdc++.h>
using namespace std;
int t;
struct member{
	int a,b,c;
};
member a[50010];
void inm(int n){
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	int num[5];
	for(int i=1;i<=n;i++){
		if(a[i].a>a[i].b&&a[i].a>a[i].c&&num[1]<n/2){
			ans+=a[i].a;
			num[1]++; 
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].b>a[i].a&&a[i].b>a[i].c&&num[2]<n/2){
			ans+=a[i].b;
			num[2]++; 
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].c>a[i].a&&a[i].c>a[i].b&&num[2]<n/2){
			ans+=a[i].c;
			num[3]++; 
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		inm(n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
