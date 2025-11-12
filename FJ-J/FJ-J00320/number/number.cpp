#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
    int k=s.length();
    int cnt=0;
    for(int i=0;i<k;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[cnt]=(s[i]-'0');
    		cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
    return 0;
}
