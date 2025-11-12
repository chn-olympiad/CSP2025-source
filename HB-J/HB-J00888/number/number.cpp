#include<bits/stdc++.h>
using namespace std;

string s;
int a[101];
int l;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	l=s.size();
	s="0"+s;
	for(int i=1;i<=l;i++)
		if(s[i]>='0' && s[i]<='9')
			a[s[i]-'0']++;
	int flag=0;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++){
			if(i>0)
				flag=1;
			if(i==0 && flag==0){
				printf("0");
				return 0;
			}
			printf("%d",i);
		}
	return 0;
}
