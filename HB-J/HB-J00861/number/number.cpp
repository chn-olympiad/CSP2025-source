#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int i;
bool cmp(int a,int b){
    return(a>b);
}
int main(){
	read("number.in",'r');
	write("number.out",'w');
	char a;
	while(cin>>a){
		if(a>='1'&&a<='9'){
			s[++i]=a-'0';
		}
	}
	sort(s+1,s+1+i,cmp);
	for(int j=1;j<=i;j++){
		cout<<s[j];
	}
return 0;
}
