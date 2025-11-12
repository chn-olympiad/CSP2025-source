

#include <bits/stdc++.h>
using namespace std;
int n,a;
int h,l,h1=1,l1=1;
int main()
{	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	cin>>h>>l;
	cin>>n;
	for(long long i=1;i<h*l;i++){
		cin>>a;
		if(a>n){
			if(l1%2==1){
				if(h1==h) l1++;
				else h1++;
			}else{
				if(h1==1) l1++;
				else h1--;
			}
		}
	}
	cout<<l1<<' '<<h1;
	return 0;
}

