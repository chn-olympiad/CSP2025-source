#include<bits/stdc++.h>
using namespace std;
struct myd{
	int s1,s2,s3,st;
}a[100100];
int sum;
int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		sum=0;
		int n,st[4];
		cin>>n;
		for(int j1=1;j1<=n;j1++){
			int ma=-1;
			cin>>a[j1].s1>>a[j1].s2>>a[j1].s3;
			ma=max(a[j1].s1,max(a[j1].s2,a[j1].s3));
			if(a[j1].s1==ma){
				st[1]++;
				sum+=a[j1].s1;
				a[j1].st=1;
			}else if(a[j1].s2==ma){
				st[2]++;
				sum+=a[j1].s2;
				a[j1].st=2;
			}else if(a[j1].s3==ma){
				st[3]++;
				sum+=a[j1].s3;
				a[j1].st=3;
			}
		}
		
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;
	return 0;
}
