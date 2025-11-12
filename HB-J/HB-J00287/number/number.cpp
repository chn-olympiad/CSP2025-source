#include<bits/stdc++.h>
using namespace std;
string s;
int x[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l1=s.size();
	int l2=1;
	for(int i=0;i<=l1;i++){
		if(s[i]>='0'&&s[i]<='9')
			x[l2++]=(int)(s[i]-'0');
	}
	l2--;
	for(int i=1;i<=l2;i++){
		for(int j=1;j<=l2-i;j++){
			if(x[j]<x[j+1]){
				swap(x[j],x[j+1]);
			}
		}
	}
	for(int i=1;i<=l2;i++)
		printf("%d",x[i]);
	return 0;
}
