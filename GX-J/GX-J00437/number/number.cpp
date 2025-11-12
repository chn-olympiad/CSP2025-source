#include<bits/stdc++.h>
using namespace std;
int n,d,x,y,h=1;
string s;
char a[150];
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	d=s.size();
	if(d==1){
		cout<<s;
	}
	else{
		for(int i=1;i<=d;i++){
			if(s[i-1]=='0'||s[i-1]=='1'||s[i-1]=='2'||s[i-1]=='3'||s[i-1]=='4'||s[i-1]=='5'||s[i-1]=='6'||s[i-1]=='7'||s[i-1]=='8'||s[i-1]=='9'){
				a[i]=s[i-1];
				n++;
			}
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				x+=1*h;
				y+=i*h;
			}
			else{
				x+=(a[i]-48)*h;
			}
			 h=h*10;
			}
		
		cout<<x-y;
	}
	return 0;
}
