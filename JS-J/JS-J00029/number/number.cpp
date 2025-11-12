#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    int i=1;
	string s;
	cin>>s;
	int z=s.size();
	for(int j=0;j<=z;j++){
		if('0'<=s[j]&&s[j]<='9'){
				a[i]=(int)(s[j]-'0');
				i++;
			}
		}
	sort(a+1,a+1+i);
	for(int j=i;j>=2;j--){
		cout<<a[j];
	}
return 0;
}
