#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	int ans,a,b,c,d,e,f,r1,r2,r3,r4,r5,r6;
	cin>>s; 
	if(s>=0&&s<=9) cout<<s;
	else if(s>=10&&s<=99){
		a=s%10;
		b=s/10;
		if(b>=a) cout<<s;
		else cout<<a*10+b;
	}else if(s>=100&&s<=999){
		c=s/100;
		b=s%100/10;
		a=s%10;
		r1=max(max(a,b),c);
		r3=min(min(a,b),c);
		if(r1!=a&&r3!=a) r2=a;
		else if(r1!=b&&r3!=b) r2=b;
		else r2=c;
		cout<<r1*100+r2*10+r3;				
	}else if(s>=1000&&s<=9999){
		r2=r3=-1;
		d=s/1000;c=s%1000/100;b=s%100/10;a=s%10;
		r1=max(max(a,b),max(c,d));
		r4=min(min(a,b),min(c,d));
		r2=min(max(a,b),max(c,d));
		r3=max(min(a,b),min(c,d));
	cout<<max(1000*r1+100*r2+10*r3+r4,1000*r1+100*r3+10*r2+r4);
    }else if(s>=10000&&s<=99999){
    	e=s/10000;d=s%10000/1000;c=s%1000/100;b=s%100/10;a=s%10;
    	r1=max(max(max(a,b),c),max(d,e));
    	r5=min(min(min(a,b),c),min(d,e));
	}
return 0; 
}
