#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,a[6];
	cin>>s;
	if(s/1000000!=0){
		cout<<s;
	    return 0;
	}
	if(s/100000!=0){
		a[0]=s/100000;
		a[1]=s%100000/10000;
		a[2]=s%10000/1000;
		a[3]=s%1000/100;
		a[4]=s%100/10;
		a[5]=s%10;
		sort(a,a+6);
	    cout<<a[5]<<a[4]<<a[3]<<a[2]<<a[1]<<a[0];
	    return 0;
	}
	if(s/10000!=0){
		a[0]=s/10000;
		a[1]=s%10000/1000;
		a[2]=s%1000/100;
		a[3]=s%100/10;
		a[4]=s%10;
		sort(a,a+5);
	    cout<<a[4]<<a[3]<<a[2]<<a[1]<<a[0];
	    return 0;
	}
	if(s/1000!=0){
		a[0]=s/1000;
		a[1]=s%1000/100;
		a[2]=s%100/10;
		a[3]=s%10;
		sort(a,a+4);
	    cout<<a[3]<<a[2]<<a[1]<<a[0];
	    return 0;
	}
	if(s/100!=0){
		a[0]=s/100;
		a[1]=s%100/10;
		a[2]=s%10;
		sort(a,a+3);
	    cout<<a[2]<<a[1]<<a[0];
	    return 0;
	}
	if(s/10!=0){
		a[0]=s/10;
		a[1]=s%10;
		sort(a,a+2);
	    cout<<a[1]<<a[0];
	    return 0;
	}
	else{
		cout<<s;
	    return 0;
    }
    return 0;
}
