#include<bits/stdc++.h>
using namespace std;
string a;
int ai[1000001],sum;
bool pyh(int s1,int s2){
return s1>s2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
	if(a[i]<='9'&&a[i]>='0'){
	ai[i]=a[i]-'0';
	sum++;
	}
	}
	sort(ai+0,ai+n+1,pyh);//从0开始排 
	for(int i=0;i<sum;i++){
	cout<<ai[i];
	}
	return 0;
}