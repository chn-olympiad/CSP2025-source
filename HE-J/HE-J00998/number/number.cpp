#include<bits/stdc++.h>
using namespace std;
char s[1000001];
long long l,a[1000001],q=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out"," w",stdout);
	cin>>s;
	l=strlen(s);
	for(int i=0;i<=l;i++){
		for(int j=0;j<=9;j++){
			if(s[i]-'0'==j){ 
			 	a[q]=j;
				q++;
				break;
			}
		}
	}
	sort(a+1,a+q);
	for(int i=q-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
