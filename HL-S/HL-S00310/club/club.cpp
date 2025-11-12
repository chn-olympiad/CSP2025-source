#include<bits/stdc++.h>
using namespace std;
int ta[10];
struct s{
	int s1,s2,s3,sn,st;
}a[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int sh[100];
	int n;
	int t;
	cin >> t;
	for (int i = 1;i <=t ;i++){
		for(int j = 1;j <=n ;j++)//!
		cin >>a[i].s1>>a[i].s2>>a[i].s3;
	a[i].st=3;
		if(a[i].s2>a[i].sn){
			a[i].sn=a[i].s2;
		a[i].st = 2;
		}
		if (a[i].s3>a[i].sn){
			a[i].sn=a[i].s3;
		}
		sh[1]=n/2;
		sh[2]=n/2;
		sh[3]=n/2;
		for (int i = 1;i <= n;i++){
			if(sh[a[i].st]>=i){ ///n/t;
				sh[a[i].st]--;
			}
		}
}
    return 0;
}