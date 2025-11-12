#include<bits/stdc++.h>
#include<stack> 
using namespace std;
int main(){
	freopen("number3.in","r");
	freopen("number3.out","w"); 
	int b[1000000000],c;
	char a[10000000];
	stack <char>am[1000000000];
    cin>>a;
    am.empty();
    am.push(a);
	int b=0;
	for(int i<=b;i++){
		c=am.top();
		if(c="1"||c="2"||c="3"||c="4"||c="5"||c="6"||c="7"||c="8"||c="9")
		{
			b+=c;
			am.pop();
		}
		else{
			am.pop();
			c=0;
		}
	} 
	if(b>0){
	cout<<b;	
	}
	else{
		cout<<0;
	}
	return 0;
}
