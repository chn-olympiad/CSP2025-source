#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long cnt=0;
	cin>>s;
	long long i=0;
	while(i<=s.size()){
		if(!islower(s[i])){
			cnt++;
			a[cnt]=s[i];
		}
		i++;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>1;i--){
		if(a[i]==' '){
			return 0;
		}
		cout<<a[i];
	}
	return 0;
} 