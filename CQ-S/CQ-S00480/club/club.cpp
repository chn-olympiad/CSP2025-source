#include <bits/stdc++.h>
using namespace std;

struct Node{
	int a,b,c;
};

priority_queue <int,vector<int >, greater<int > > fc;
priority_queue <int,vector<int >, greater<int > > sc;
priority_queue <int,vector<int >, greater<int > > tc;

int a[200000],b[200000],c[200000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		while (!fc.empty()) fc.pop();
		while (!sc.empty()) sc.pop();
		while (!tc.empty()) tc.pop();
		int n;
		cin>>n;
		int m=0;
		int ans=0,sum=0,num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				fc.push(min(a[i]-b[i],a[i]-c[i]));
				ans++;
				m+=a[i];
//				cout<<a[i]<<" a\n";
			} 
			else if(b[i]>=c[i]&&b[i]>a[i]){
				sc.push(min(b[i]-a[i],b[i]-c[i]));
				sum++;
				m+=b[i];
//				cout<<b[i]<<" b\n";
			} 
			else if(c[i]>=b[i]&&c[i]>a[i]){
				tc.push(min(c[i]-a[i],c[i]-b[i]));
				num++;
				m+=c[i];
//				cout<<c[i]<<" c\n";
			}
		}
		if(ans > n/2){
			while(ans > n/2){
				m-=fc.top();
				fc.pop();
				ans--;
			}
		}
		if(sum > n/2){
			while(sum > n/2){
				m-=sc.top();
				sc.pop();
				sum--;
			}
		}
		if (num > n/2){
			while(num > n/2){
				m-=tc.top();
				tc.pop();
				num--;
			}
		}
		cout<<m<<endl;
	} 
	return 0;
} 
/*
1
10 
2020 14533 18961 
2423 15344 16322 
1910 6224 16178  
2038 9963 19722 
8375 10557 5444 
3518 14615 17976  
6188 13424 16615 
8769 509 4394 
958 3195 9953 
16441 5313 10926
*/
