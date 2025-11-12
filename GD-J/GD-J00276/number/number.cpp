#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cur,n,ans;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++cur]=(s[i]-'0');
	}
	sort(a+1,a+cur+1);
	for(int i=cur;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
/*
history:
	8:30 start!
	8:39 successfully open Virtual Box and read problems
	8:49 AC T1 and check big sample(correct)
	8:51 read T2 is a xiao-mo-ni good luck.
	9:21 AC T2(because 1.n*m instead of n in lower_bound 2.foget the sample test)
	9:22 read T3 and T4 but don't know how to do
	10:54 !!! still dont know how to do T3&4 
	11:21 T3=10+20(A+B)=30pts
	11:45 T4=暴力枚举子集=[30,40]pts 
*/
