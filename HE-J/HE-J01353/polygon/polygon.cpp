#include<bits/stdc++.h>
using namespace std;
int t[10000],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	int s[101]={};
	int cnt=0;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	for(int i=1;i<=n*m;i++){
		s[a[i]]++;
		if(a[i]>a[1])
			cnt++;
	}
	cnt++;
	if((cnt%n+cnt/n)%2!=0){//当R不处于偶数列，座位是由上到下的 
		if(cnt/n==0){//当R在第一列时 
			if(cnt%n==0)//当R在这列最后一个位置时 
				cout<<1<<" "<<n;
			else//不在最后一排时 
				cout<<1<<" "<<cnt%n;//输出在第一列，在cnt%n排 
		}
		else{//当R在非1排的奇数排时 
			if(cnt%n==0) 
				cout<<cnt/n<<" "<<n;//输出在cnt/n列 ，在最后一排 
			else
				cout<<cnt/n+1<<" "<<cnt%n;
		}
	}
	else if((cnt%n+cnt/n)%2==0){//当R在偶数列时，位置是反的 
		if(cnt/n==0){ 
			if(cnt%n==0)
				cout<<cnt/n<<" "<<n;
			else
				cout<<cnt/n<<" "<<n;
		}
		else{
			if(cnt%n==0)
				cout<<cnt/n<<" "<<n;
			else
				cout<<cnt/n+1<<" "<<n;
		}
	}
	return 0;
}
