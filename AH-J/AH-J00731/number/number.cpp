#include<bits/stdc++.h>
using namespace std;
char c[1000005];
long long a[1000005],i=1,j=1,sum;

int cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c[i]){
		if(0<=c[i]-'0' && c[i]-'0'<=9) {
			a[j]=c[i]-'0',j++;
		}
		i++;
	}
	j--;
	sort(1+a,1+a+j,cmp);
	for(int x=1;x<=j;x++){
		cout<<a[x];
	}
	return 0;
}
