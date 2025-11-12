#include<bits/stdc++.h>
using namespace std;
int a[1000005],x;
int cmp(int x,int y)
{
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ls=s.size();
    for(int i=0;i<=ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=int(s[i]-'0');
			x+=1;
		}
	}
	x-=1;
	sort(a,a+x,cmp);
	for(int i=0;i<=x;i++) cout<<a[i];
    return 0;
}
