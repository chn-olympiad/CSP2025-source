#include<bits/stdc++.h>
using namespace std;
int a[1000005],l,j=1;
char s[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++)cout<<a[i];
	return 0;
}
