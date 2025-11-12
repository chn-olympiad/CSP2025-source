#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	int t;
	int n;
	int a[100000],b[100000],c[100000];
	int s1,s2,s3;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		for(i=1;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];	
		}
		for(i=0;i<n;i++){
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			int k=n/2;
			if(a[i]>b[i]&&a[i]>c[i]){
				s1++;
			}
		}
	}
	cout<<0;
	return 0;
}
