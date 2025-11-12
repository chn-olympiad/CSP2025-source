#include<bits/stdc++.h>
using namespace std;
bool deng(const int & a,const int & b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s,i=0;
	cin>>s;
	int a[1005]={0};
	while(s%10!=0){
		i++;
		a[i]=s%10;
		s/=10;
	}
	sort(a+1,a+1+i,deng);
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
	return 0;
}

