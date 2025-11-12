#include<bits/stdc++.h>
using namespace std; 
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;  
	cin>>n;
     int g=n/1%10;
     int s=n/10%10;
     int b=n/100%10;
     int q=n/1000%10;
     if(g>=b&&g>=s&&g>=q&&s>=b&&s>=q&&b>=q)
     {
     	cout<<g*1000+s*100+b*10+q*1;
	 }
	 else if(g>=b&&g>=s&&g>=q&&s>=b&&s>=q&&q>=b)
     {
     	cout<<g*1000+s*100+q*10+b*1;
	 }
	 else if(g>=b&&g>=s&&g>=q&&b>=s&&b>=q&&s>=q)
     {
     	cout<<g*1000+b*100+s*10+q*1;
	 }
	 else if(g>=b&&g>=s&&g>=q&&b>=s&&b>=q&&q>=s)
     {
     	cout<<g*1000+s*100+q*10+b*1;
	 }
	 else if(g>=b&&g>=s&&g>=q&&q>=b&&q>=s&&b>=s)
     {
     	cout<<g*1000+q*100+b*10+s*1;
	 }
	 else if(g>=b&&g>=s&&g>=q&&q>=b&&q>=s&&s>=b)
     {
     	cout<<g*1000+q*100+s*10+b*1;
	 }//1*6
	 else if(s>=g&&s>=b&&s>=q&&g>=b&&g>=s&&b>=q)
     {
     	cout<<s*1000+g*100+b*10+q*1;
	 }
	 else if(s>=g&&s>=b&&s>=q&&g>=b&&g>=s&&q>=b)
     {
     	cout<<s*1000+g*100+q*10+b*1;
	 }
	 else if(s>=g&&s>=b&&s>=q&&b>=g&&b>=q&&g>=q)
     {
     	cout<<s*1000+b*100+g*10+q*1;
	 }
	 else if(s>=g&&s>=b&&s>=q&&b>=g&&b>=q&&q>=g)
     {
     	cout<<s*1000+b*100+q*10+g*1;
	 }
	 else if(s>=g&&s>=b&&s>=q&&q>=g&&q>=b&&g>=b)
     {
     	cout<<s*1000+q*100+g*10+b*1;
	 }
	 else if(s>=g&&s>=b&&s>=q&&q>=g&&q>=b&&b>=g)
     {
     	cout<<s*1000+q*100+b*10+g*1;
	 }//2*6
	 else if(b>=g&&b>=s&&b>=q&&g>=b&&g>=q&&s>=q)
     {
     	cout<<b*1000+g*100+s*10+q*1;
	 }
	 else if(b>=g&&b>=s&&b>=q&&g>=b&&g>=q&&q>=s)
     {
     	cout<<b*1000+g*100+q*10+s*1;
	 }
	 else if(b>=g&&b>=s&&b>=q&&s>=b&&s>=q&&g>=q)
     {
     	cout<<b*1000+s*100+g*10+q*1;
	 }
	 else if(b>=g&&b>=s&&b>=q&&s>=b&&s>=q&&q>=g)
     {
     	cout<<b*1000+s*100+q*10+g*1;
	 }
	 else if(b>=g&&b>=s&&b>=q&&q>=b&&q>=g&&g>=s)
     {
     	cout<<b*1000+q*100+g*10+s*1;
	 }
	 else if(b>=g&&b>=s&&b>=q&&q>=b&&q>=g&&s>=g)
     {
     	cout<<b*1000+q*100+s*10+g*1;
	 }//3*6
	 else if(q>=g&&q>=s&&q>=b&&g>=b&&g>=s&&s>=b)
     {
     	cout<<q*1000+g*100+s*10+b*1;
	 }
	 else if(q>=g&&q>=s&&q>=b&&g>=b&&g>=s&&b>=s)
     {
     	cout<<q*1000+g*100+b*10+s*1;
	 }
	 else if(q>=g&&q>=s&&q>=b&&s>=g&&s>=b&&g>=b)
     {
     	cout<<q*1000+s*100+g*10+b*1;
	 }
	 else if(q>=g&&q>=s&&q>=b&&s>=g&&s>=b&&b>=g)
     {
     	cout<<q*1000+s*100+b*10+g*1;
	 }
	 else if(q>=g&&q>=s&&q>=b&&b>=g&&b>=s&&g>=s)
     {
     	cout<<q*1000+b*100+g*10+s*1;
	 }
	 else if(q>g&&q>s&&q>b&&b>g&&b>s&&b>g)
     {
     	cout<<q*1000+s*100+b*10+g*1;
	 }//4*6
	return 0;
}

