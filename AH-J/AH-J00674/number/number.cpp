#include<bits/stdc++.h>
using namespace std;
int a[100010];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++){
        if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
            sum++;
        }

	}
	for(int i=0;i<s.size();i++){
        for(int j=1;j<=sum;j++){
            if(s[i]=='0' or s[i]=='1' or s[i]=='2' or  s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9')
                a[j]=s[i]-'0';
        }
	}
	sort(a+1,a+sum+1);
	for(int j=sum;j>=1;j--)
	cout<<a[j];
    return 0;
  }
