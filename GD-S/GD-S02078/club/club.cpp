#include<bits/stdc++.h>
using namespace std;
struct myd{
	int first;
	int second;
	int third;
}a[100010];
int n;
bool cmp1(myd x,myd y){
	return x.first>y.first;

}
bool cmp2(myd x,myd y){
	return x.second>y.second;

}
bool cmp3(myd x,myd y){
	return x.third>y.third;

}
int clubone(int n){
	int sum=0;
	sort(a+1,a+n+1,cmp1);
	if(n%2!=0){
		n+1;
	}
	for(int i=1;i<=n/2;i++){
		sum+=a[i].first;
	}
	return sum;
}
int clubtwo(int n){
	int sum=0;
	sort(a+1,a+n+1,cmp2);
	if(n%2!=0){
		n+1;
	}
	for(int i=1;i<=n/2;i++){
		sum+=a[i].second;
	}
	return sum;
}
int clubthree(int n){
	int sum=0;
	sort(a+1,a+n+1,cmp3);
	if(n%2!=0){
		n+1;
	}
	for(int i=1;i<=n/2;i++){
		sum+=a[i].third;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].first>>a[i].second>>a[i].third;
		}
		if(clubone(n)>clubtwo(n)&&clubone(n)>clubthree(n)){
			ans+=clubone(n);
			int sum=0;
		//	sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				a[i].first=0;
				a[i].second=0;
				a[i].third=0;
			}
			int m1=0,m2=0,y1,y2;
			if(clubtwo(n)>clubthree(n)){	
				ans+=clubtwo(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubthree(n);
			}
			else{
				ans+=clubthree(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubtwo(n);
			}
		}
		else if(clubtwo(n)>clubone(n)&&clubtwo(n)>clubthree(n)){
			ans+=clubtwo(n);
			int sum=0;
		//	sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				a[i].first=0;
				a[i].second=0;
				a[i].third=0;
			}
			if(clubtwo(n)>clubthree(n)){	
				ans+=clubtwo(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubthree(n);
			}
			else{
				ans+=clubthree(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubtwo(n);
			}
			if(clubone(n)>clubthree(n)){
				ans+=clubone(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubthree(n);
			}
			else{
				ans+=clubthree(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubone(n);
			}
		}
		else if(clubtwo(n)<clubthree(n)&&clubone(n)<clubthree(n)){
			ans+=clubthree(n);
			int sum=0;
		//	sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				a[i].first=0;
				a[i].second=0;
				a[i].third=0;
			}
			if(clubone(n)>clubtwo(n)){
				ans+=clubone(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubtwo(n);
			}
			else{
				ans+=clubtwo(n);
		//		sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					a[i].first=0;
					a[i].second=0;
					a[i].third=0;
				}
				ans+=clubone(n);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
