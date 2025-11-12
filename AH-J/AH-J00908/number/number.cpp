#include<bits/stdc++.h>
using namespace std;
long long i,len,cnt,a[1000010];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
    }
	sort(a+1,a+cnt+1);
	for(i=cnt;i>=1;i--){
		cout<<a[i];
	}
    return 0;
}
