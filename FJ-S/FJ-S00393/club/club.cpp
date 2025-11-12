#include<bits/stdc++.h>
using namespace std;
int t;
int n[10];
struct node {
	int a,b,c;
} a[100086];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n[i];
		for(int j=0; j<n[i]; j++) {
			cin>>a[j].a>>a[j].b>>a[j].c;
		}
	}
	for(int i=0; i<t; i++) {
		int max[100086];
		int sum=0;
		int maxa=0;
		for(int j=0;j<n[i];j++) {
				if(a[j].a>=a[j].b) {
					maxa=a[j].a;
				} else {
					maxa=a[j].b;
				}
				
				if(maxa>=a[j].c) {
					sum+=maxa;
				} else {
					sum+=a[j].c;
				}
			}
		
		cout<<sum<<endl;
		sum=0;
}
	return 0;
}
