#include <bits/stdc++.h>
using namespace std;
int a[1000];
void pop(int len){
	for (int j=len;j>1;j--){
		for (int i=0;i<j-1;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string s;
	int n,m;
	int k,R=0,R_;
	int c,r;
	bool flag=1;
	cin>>n>>s;
	m=s[0]-'0';
	int may=1;
	if(s[1]=='0'){
		may=2;
		m=10;
	}
	for (int i=may;i<s.size();i++){
		R=R*10+s[i]-'0';
	}
	cout<<n<<' '<<m<<' '<<R<<endl;
	k=n*m;
	a[0]=R;
	for (int i=1;i<k;i++){
		cin>>a[i];
	}
	pop(k);
	for (int i=0;i<k;i++){
		if(a[i]==R){
			R_=i+1;
		}
	}
	c=(R_-1)/n+1;
	R_=R_-(c-1)*n;
	if(c%2){
		r=R_;
	}
	else{
		r=m+1-R_;
	}
	cout<<c<<' '<<r;
}