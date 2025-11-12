#include<bits/stdc++.h>
using namespace std;
int main(){
	feropen("number.in","r","stdin")
	feropen("number.out","w","stdout")
	int a,s,d;
	cin>>a;
	s=a/1%10;
	
	d=a/10%10;
	if(a>=10){
	
	if(s>d)	{
		cout<<s<<d;
	}	
	if(s<d)	{
		cout<<d<<s;
	}	
}
    if(a<10)
    cout<<a;
	return 0 ;
} 
