#include <bits/stdc++.h>
using namespace std;
string s;
int a[1005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
    cin>>s;
    int j=0;
    for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=(int)(s[i]-48);
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<=j-1;i++)cout<<a[i];
	return 0;
}
