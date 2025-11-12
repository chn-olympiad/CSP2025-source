#include<bits/stdc++.h>
#include<cstring>
using namespace std;
char s[1000000],ch;
int a[1000000];
int b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000000);
	int n=strlen(s);
	int j=1;
	for(int i=0;i<n;i++){
		ch=s[i];
		if((ch>='0'&&ch<='9')&&(ch>'z'||ch<'a')){
			a[j]=s[i]-'0';
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		int mymax=-1,zb=0;
		for(int j=1;j<=n;j++){
			if(mymax<a[j]){
				mymax=a[j];
				zb=j;
			}
		}
		a[zb]=-1;
		b[i]=mymax;
	}
	bool flag=1;
	for(int i=1;i<j;i++){
		cout<<b[i];
	}
	return 0;
} 
