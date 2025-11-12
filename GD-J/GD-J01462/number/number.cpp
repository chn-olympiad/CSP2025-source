#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cmp(int a,int b){
    return a>b;
}
int check(char c){
    if(c=='0')return 0;
    if(c=='1')return 1;
    if(c=='2')return 2;
    if(c=='3')return 3;
    if(c=='4')return 4;
    if(c=='5')return 5;
    if(c=='6')return 6;
    if(c=='7')return 7;
    if(c=='8')return 8;
    if(c=='9')return 9;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[N];
    int j=0;
    for(int i=0;i<s.size();i++){
    	if(s[i]<'9'&&s[i]>'0'){
    		a[j]=check(s[i]);
    		j++;
		}
    	if(s[i]=='9'||s[i]=='0'){
    		a[j]=check(s[i]);
    		j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++)cout<<a[i];
    return 0;
}
