#include <bits/stdc++.h> 
using namespace std;
int a[1000000]={0},x=0;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='1' && s[i]<='9'){
			x++;
			a[x]=(int)s[i];
			
		}
	}
	
	sort(a,a+x,cmp);
	for(int j=1;j<=x;j++){
		cout<<a[j]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
