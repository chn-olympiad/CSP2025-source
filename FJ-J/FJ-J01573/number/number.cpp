#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
char s[1000001];
long long a[1000001],ans,num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
cin>>s;
for(long long i=0;i<1000001;i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[ans]=s[i]-'0';
		ans++;
	}
	else if(s[i]>='a'&&s[i]<='z'){
		continue;
	}
	else{
		break;
	}
}
sort(a,a+ans,cmp);
int i=0;
while(ans>0){
	num=a[i]+num*10;
	i++;
	ans--;
}
cout<<num;
	return 0;
}

