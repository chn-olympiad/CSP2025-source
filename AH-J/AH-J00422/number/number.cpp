#include<bits/stdc++.h>
using namespace std;
string s;
int a[1010],b[1010];
int j=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)s[i]-'0';
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int f=0;f<j;f++){
		cout<<a[f];
	}
    return 0;
}
