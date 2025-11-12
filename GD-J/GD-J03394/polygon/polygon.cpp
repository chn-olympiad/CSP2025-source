#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0,maxx=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(sum>maxx*2)cout<<maxx;
	else cout<<0;
	return 0;
}
//8:30 start to write code.I think that I can get the sencond prize.
//9:01 slove question 1
//9:07 try to slove question 2
//9:38 slove question 2
//9:41 question 3 is too difficult.I suppose that I can slove specal example A or B.
//10:10 slove specal example A.But specal example B looks a bit difficult.How can I do?
//10:20 I can't find out the key to slove this problem.
//10:24 slove specal example B.hahaha,I will sleep.
//10:41 question 4 is difficult too.try to solve test 1.
//10:50 slove test 1.I can get the 12 point.
//My first CSP_J2 is end. I want to have a try next year!
//wax I love you!
