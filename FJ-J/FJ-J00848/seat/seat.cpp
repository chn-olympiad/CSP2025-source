#include<bits/stdc++.h>
//#define LOCAL_
using namespace std;

//easy?

int n,m;
int a[128];
int key;


int main() {
#ifndef LOCAL_
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
#endif

	cin.tie(0)->sync_with_stdio(0);

	cin>>n>>m;
	int s = n*m,no = 0;
	//cout<<"s="<<s<<endl;
	for(int i = 1; i<=s; i++) {
		cin>>a[i];
		if(i==1)key = a[i];
	}

	sort(a+1,a+s+1,greater<int>());

	for(int i = 1; i<=s; i++) {
		if(a[i] == key) {
			no = i;
			break;
		}
	}

	int c ,r;
	if(no%n == 0){
		c = no/n;
	}else{
		c = no/n+1;
	}
	cout<< c<<" ";
	if(c%2 == 0){
		if(no%n == 0){
			r = 1;
		}else{
			r = n-no%n+1;
		}
	}else{
		if(no%n == 0){
			r = n;
		}else{
			r = no%n;
		}
	}
	cout<<r<<endl;


	    return 0;
}
