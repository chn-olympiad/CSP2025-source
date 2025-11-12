#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m=0,i=0;
	cin>>s;
	int len=s.length();
	for(i=0;i<len;i++){
		a[m]=0;
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]>'0')a[m]++;
			if(s[i]>'1')a[m]++;
			if(s[i]>'2')a[m]++;
			if(s[i]>'3')a[m]++;
			if(s[i]>'4')a[m]++;
			if(s[i]>'5')a[m]++;
			if(s[i]>'6')a[m]++;
			if(s[i]>'7')a[m]++;
			if(s[i]>'8')a[m]++;
			if(s[i]>'9')a[m]++;
			m++;
		}
    }
	sort(a,a+1+m);
    for(i=m;i>0;i--){
		cout<<a[i];
    }
 	return 0;
}
