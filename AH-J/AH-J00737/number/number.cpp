#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
long long a[11];
string s,n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long sum=s.size();
    for(int i=0;i<sum;i++){//s.size is wrong?OK I know;
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
			//cout<<a[s[i]-'0']<<" "<<s[i]-'0'<<"\n";
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&n==""){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			n=n+char(i+'0');
		}
	}
	cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
