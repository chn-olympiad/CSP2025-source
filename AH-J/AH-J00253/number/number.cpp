#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size(),x=0;
    for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;			
			a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		printf("%d",a[i]);
	}
    return 0;
}
