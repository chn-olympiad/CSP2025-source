#include<bits/stdc++.h>
using namespace std;

const int N=1e6+100;
char s[N];
int a[N],len;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=strlen(s);
	int t=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<t;i++){
		cout<<a[i];
	}
	
	return 0;
}

