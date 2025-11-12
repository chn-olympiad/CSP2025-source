#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000005],sum;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(!isdigit(a[i])){
			continue;
		}else{
			n[sum]=a[i]-'0';
			sum++;
		}
	}
	sort(n,n+sum,cmp);
	if(n[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<sum;i++){
		cout<<n[i];
	}
	return 0;
}


