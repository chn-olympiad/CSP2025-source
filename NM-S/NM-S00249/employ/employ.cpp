#include <bits/stdc++.h>
using namespace std;

int main(){
int n,a,b,ans=0;
cin>>n;
cin>>a;
int g,s,h;
g=a%10;
s=a/10%10;
h=a/100%10;
if(g==1) ans+=1;
if(s==1) ans+=1;
if(h==1) ans+=1;
cout<<ans;
	return 0;
}
