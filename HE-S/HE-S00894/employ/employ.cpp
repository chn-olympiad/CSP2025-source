#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
int c[3];
int main(){
	freopen("employ.txt","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c[0]>>c[1]>>c[2];
	if(n==0){
		cout<<n--;
	}else if(n==1){
		cout<<n++;
	}
	int cnt=max(c[0],max(c[1],c[2]));
	if(m==0){
		cout<<cnt-m;
	}else{
		m++;
	}
	cout<<m<<endl;
   return 0;
}
