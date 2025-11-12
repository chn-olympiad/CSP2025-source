#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t1,t2,t3,t4,t5,
	n,first,second,third,
	one[20000],two[20000],three[20000],
	a[100000];
cin>>n>>first;
for(int j=1;j<=first;j++){
	for(int i=1;i<=3;i++){
	cin>>one[i];}
	sort(one+1,one+1+3);
	a[j]=one[3];
	t1+=a[j];
	}
	cout<<t1<<endl;
cin>>second;
for(int j=1;j<=second;j++){
	for(int i=1;i<=3;i++){
	cin>>two[i];}
	sort(two+1,two+1+3);
	a[j]=two[3];
	t2+=a[j];
	}
	cout<<t2<<endl;
cin>>third;
for(int j=1;j<=third;j++){
	for(int i=1;i<=3;i++){
	cin>>three[i];}
	sort(three+1,three+1+3);
	a[j]=three[3];
	t3+=a[j];
	}
	cout<<t3<<endl;
return 0;
	}

