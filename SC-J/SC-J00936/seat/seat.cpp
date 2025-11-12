#include<bits\stdc++.h>
#define ll long long
#define endl '\n'
#define str string
using namespace std;
int n,m,i,ii,x,y,ans,in;
bool cmp(int a,int b){
	return a>b;
}
int main(int argc,char *argv[]){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>ii;
	for(i=1;i<n*m;i++){
		cin>>in;
		if(in>ii)
		 ans++;
	}
	x=ans/n+1;
	if(x%2)
	 y=ans%n+1;
	else//x%2==0
	 y=n-ans%n;
	cout<<x<<' '<<y;
	return 0;
}

//2 2
//99 100 97 98
//1 2

//2 2
//98 99 100 97
//2 2

//3 3
//94 95 96 97 98 99 100 93 92
//3 1

//i=94,ans=6
//100 99 98 97 96 95 94 93 92



//#include<bits\stdc++.h>
//#define ll long long
//#define endl '\n'
//#define str string
//using namespace std;
//int n,m,i,x,y;
//bool cmp(int a,int b){
//	return a>b;
//}
//int main(int argc,char *argv[]){
////	freopen("seat.in","r",stdin);
////	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	vector<int> a(n*m);
//	for(;i<n*m;i++)
//	 cin>>a[i];
//	i=a[0];
//	sort(a.begin(),a.end(),cmp);
////	cout<<i<<endl;
////	for(auto num:a)
////	 cout<<num<<' ';
////	cout<<endl;
////	i=lower_bound(a.begin(),a.end(),i)-a.begin();
////	cout<<i;
//	int l=0,r=n*m-1,ans=-1,mid;
//	while(l<=r){
//		mid=(l+r)/2;
//		if(a[mid]==i){
//			ans=mid;
//			break;
//		}
//		if(a[mid]>i)
//			l=mid;
//		else if(a[mid]<i)
//			r=mid;
//	}
////	cout<<ans<<endl;
//	x=ans/n+1;
//	if(x%2)
//	 y=ans%n+1;
//	else//x%2==0
//	 y=n-ans%n;
//	cout<<x<<' '<<y;
//	return 0;
//}

//2 2
//99 100 97 98
//1 2

//2 2
//98 99 100 97
//2 2

//3 3
//94 95 96 97 98 99 100 93 92
//3 1

//i=94,ans=6
//100 99 98 97 96 95 94 93 92



//#include<bits\stdc++.h>
//#define ll long long
//#define endl '\n'
//#define str string
//using namespace std;
//int n,m,i,x,y;
//bool cmp(int a,int b){
//	return a>b;
//}
//int main(int argc,char *argv[]){
////	freopen("seat.in","r",stdin);
////	freopen("seat.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	vector<int> a(n*m+1);
//	for(i=1;i<=n*m;i++)
//	 cin>>a[i];
//	i=a[1];
//	sort(a.begin()+1,a.end(),cmp);
////	cout<<i<<endl;
////	for(auto num:a)
////	 cout<<num<<' ';
////	cout<<endl;
////	i=lower_bound(a.begin()+1,a.end(),i)-a.begin();
////	cout<<i;
//	int l=1,r=n*m,ans=-1,mid;
//	while(l<=r){
//		mid=(l+r)/2;
//		if(a[mid]==i){
//			ans=mid;
//			break;
//		}
//		if(a[mid]>i)
//		 l=mid;
//		else if(a[mid]<i)
//		 r=mid;
//	}
////	cout<<ans<<endl;
//	if(ans%n)
//	 x=ans/n+1;
//	else//ans%n==0
//	 x=ans/n;
//	if(x%2){
//		if(ans%n)
//		 y=ans%n;
//		else//ans%n==0
//		 y=n;
//	}
//	else{//x%2==0
//		if(ans%n)
//		 y=n-ans%n+1;
//		else//ans%n==0
//		 y=n;
//	}
//	cout<<x<<' '<<y;
//	return 0;
//}

//3 3
//94 95 96 97 98 99 100 93 92

//i=94,ans=7
//100 99 98 97 96 95 94 93 92