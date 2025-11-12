#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
string s;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[int(s[i]-'0')]++; 
		}
	}
	for(int i=9;i!=-1;i--){
		for(int j=0;j<a[i];j++)
		    printf("%d",i);
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

