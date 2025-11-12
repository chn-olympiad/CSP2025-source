# include<bits/stdc++.h>
using namespace std;
string a;
int ZF[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a; 
	for(char i:a)if(i>='0'&&i<='9')ZF[i-'0']++;
	for(int i = 9;~i;i--)while(ZF[i]--)cout<<i;
	return 0;
} 
