#include<bits/stdc++.h>
using namespace std;
string s,n="";
long long a,b,c,d,e,f,g,h,x,y;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a++;
		else if(s[i]=='1') b++;
		else if(s[i]=='2') c++;
		else if(s[i]=='3') d++;
		else if(s[i]=='4') e++;
		else if(s[i]=='5') f++;
		else if(s[i]=='6') g++;
		else if(s[i]=='7') h++;
		else if(s[i]=='8') x++;
		else if(s[i]=='9') y++;
	}
	while(y>0) n+="9",y--;
	while(x>0) n+="8",x--;
	while(h>0) n+="7",h--;
	while(g>0) n+="6",g--;
	while(f>0) n+="5",f--;
	while(e>0) n+="4",e--;
	while(d>0) n+="3",d--;
	while(c>0) n+="2",c--;
	while(b>0) n+="1",b--;
	while(a>0) n+="0",a--;
	cout<<n;
	return 0;
}
