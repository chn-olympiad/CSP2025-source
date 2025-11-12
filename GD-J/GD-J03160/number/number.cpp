#include<bits/stdc++.h>
using namespace std;

int n;
int b[1000010],x=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		
		if(s[i]>='0'&&s[i]<='9'){
		   x++;
		   b[x]=int(s[i]-'0');
	    }
	}
	sort(b+1,b+x+1,cmp);
	for(int i=1;i<=x;i++){
		printf("%d",b[i]);
	}
	return 0;
} 
