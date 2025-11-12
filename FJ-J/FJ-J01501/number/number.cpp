#include<bits/stdc++.h>
using namespace std;
string s;
queue<int>q;
int a[1000010],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	int x=s.size();
	for(int i=0;i<x;i++){
		if((int)s[i]<=57&&(int)s[i]>=48){
			q.push((int)s[i]-48);
			sum++;
		}
	}
	for(int j=0;j<sum;j++){
		a[j]=q.front();
		q.pop();
	}
	sort(a,a+sum+1);
	for(int i=sum;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
