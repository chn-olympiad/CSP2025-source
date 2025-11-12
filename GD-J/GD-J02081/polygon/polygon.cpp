//5000,should be n2 
//and, needs the max of many sticks,so feng kuai?
//no idea with the add up of random sticks....... so n! * n^1/2
//20 pts.
//11:18 back to work
//wait it seems like i cant get any pts....
//but 15~20 max == 1
//than any 3 sticks can make a polygon
//cout<<c(3,n)
//and 1~3 can be done with tri
//i m so clever!
//how do you calculate c()???
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if(n <= 3){
		cout<<a[1] + a[2] > a[3] && a[3] + a[1] > a[2] && a[2] + a[3] > a[1];
	}
	else if(a[1]){
		long long ans=1;
		for(int i = 1;i <= n;i ++){
			ans *= n;
			ans %= 998244353;
		}
		cout<<ans+1;
	}
} 
//10:53 one hour left,maybe i can get some rest
//11:15 EDGESURF 7820 ,got caught by 10 octopus

