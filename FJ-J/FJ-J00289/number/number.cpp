#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000010];
int sum=0,t;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);	
	getline(cin,a);
	int k=a.size();
	for(int i=0;i<k;i++){
		if(a[i]<='9' && a[i]>='0'){
			sum++;
			n[sum]=a[i]-48;
		}
	}
	sort(n+1,n+sum+1);
	for(int i=sum;i>=1;i--)
		printf("%d",n[i]);
	return 0;
}
