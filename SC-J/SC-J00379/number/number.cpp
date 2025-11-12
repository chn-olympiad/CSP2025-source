#include<bits/stdc++.h>
using namespace std;
long long a[1000005],num,cnt,b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
			num++;
		}
	}
	sort(a+0,a+s.size()+1);
	for(int i=s.size();i>=0;i--){
		if(a[i]>=1 && a[i]<=9){
			cout <<a[i];
			cnt++;
		}
	}
	if(num>cnt){
		for(int i=1;i<=num-cnt;i++){
			cout <<0;
		}
	} 
	return 0;
}