#include <bits/stdc++.h>
using namespace std;
int s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s<10) cout<<s;
	else if(s>=10 && s<100 && s/10>s%10) cout<<s;
	else if(s>=10 && s<100 && s/10<s%10) cout<<(s%10*10)+s/10;
	else if(s>=10 && s<100 && s/10==s%10) cout<<s;
	else if(s>=100 && s<1000 && s/100>s/10%10 && s/100>s%10 && s/10%10>s%10) cout<<s;
	else if(s>=100 && s<1000 && s/100>s/10%10 && s/100>s%10 && s/10%10<s%10) cout<<(s/100*100)+(s%10*10)+(s/10%10);
	else if(s>=100 && s<1000 && s/10%10>s/100 && s/10%10>s%10 && s/100>s%10) cout<<(s/10%10*100)+(s/100*10)+(s%10);
	else if(s>=100 && s<1000 && s/10%10>s/100 && s/10%10>s%10 && s/100<s%10) cout<<(s/10%10*100)+(s%10*10)+(s/100);
	else if(s>=100 && s<1000 && s%10>s/100 && s%10>s/10%10 && s/100>s/10%10) cout<<(s%10*100)+(s/100*10)+(s/10%10);
	else if(s>=100 && s<1000 && s%10>s/100 && s%10>s/10%10 && s/100<s/10%10) cout<<(s%10*100)+(s/10%10*10)+(s/100);
	else if(s>=100 && s<1000 && s%10==s/100 && s%10==s/10%10 && s/100==s/10%10) cout<<s;
	else cout<<s;
	return 0;
}
