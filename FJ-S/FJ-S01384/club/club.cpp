#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void qwe(){
	int n,b;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b>>b;
	}
	b=0;
	sort(a,a+n,cmp);
	for(int i=0;i<n/2;i++){
		b+=a[i];
	}
	cout<<b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		qwe();
		cout<<endl;
	}
	return 0;
} 
