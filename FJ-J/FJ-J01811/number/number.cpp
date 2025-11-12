#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.length(),sum=0;
	int c[b+1]={};
	for(int i=0;i<b;i++){
		if('0'<=a[i] and a[i]<='9'){
			sum++;
			c[sum]=a[i]-'0';
		}
	}
	sort(c+1,c+1+sum);
	for(int i=sum;i>=1;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

