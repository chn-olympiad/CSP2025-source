#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
return a>b;
}
const int N=1e6+10;
string s;
int k;
char num[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') num[k++]=s[i];
	}
	sort(num,num+k,cmp);
	for(int i=0;i<k;i++)
	cout<<num[i];
    return 0;
}
