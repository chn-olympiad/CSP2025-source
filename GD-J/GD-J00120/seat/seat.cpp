#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[1000010];
long long b2=0,ans;
long long c2=1; 
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long zong=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int cnt=a[1];
	sort(a+1,a+1+zong,cmp);

	for(int i=1;i<=n*m;i++){
		b2++;
		if(cnt==a[i]){
			ans=b2;
			break;
		}
	}
	//cout<<ans;
	long long a2=ans/m;
	if(ans%m==0){
		c2=a2;
		//cout<<c2;
	}else{
		c2=a2+1;
		//cout<<c2;
	}


	long long b3,b4,b5;
	if(ans<=n){
		cout<<c2<<" "<<ans;
	}else if(ans>n){
		if(c2%2==0){
			b3=ans-(c2-1)*m;
			//cout<<b3;
			b4=ans-(c2-1)*m;
			b5=n-b4+1;//m-(ans-1)
			cout<<c2<<" "<<b5;
		}else{
			cout<<c2<<" "<<ans-(c2-1)*m;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98
1 2

2 2
98 99 100 97
2 2

3 3
94 95 96 97 98 99 100 93 92
3 1


3 3
5 9 8 7 6 4 3 2 1
2 2

4 3
6 12 11 10 9 8 7 5 4 3 2 1
2 3
*/


