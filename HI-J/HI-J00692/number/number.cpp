#include<bits/stdc++.h>
using namespace std;
char s[100005]={-1},a[100005]={-1},x=1;
int main(){
	fronpen("number.in","r",stdin);
	fronpen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=100005;i++){
		if(s[i]<='9'&&s[i]>='0'){
			if(s[i]=='0'){
				a[x]=0;x++;
			}
			if(s[i]=='1'){
				a[x]=1;x++;
			}
			if(s[i]=='2'){
				a[x]=2;x++;
			}
			if(s[i]=='3'){
				a[x]=3;x++;
			}
			if(s[i]=='4'){
				a[x]=4;x++;
			}
			if(s[i]=='5'){
				a[x]=5;x++;
			}
			if(s[i]=='6'){
				a[x]=6;x++;
			}
			if(s[i]=='7'){
				a[x]=7;x++;
			}
			if(s[i]=='8'){
				a[x]=8;x++;
			}
			if(s[i]=='9'){
				a[x]=9;x++;
			}
		}
	}
	sort(a+1,a+x+1);
	int l=0,m=1;
	for(int i=1;i<=x;i++){
		l+=a[i]*m;
		m*=10;
	}
	cout<<l;
	return 0;
}
