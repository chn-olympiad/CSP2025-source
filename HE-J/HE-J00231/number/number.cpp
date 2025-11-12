#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50;
string s;
int num[N];
bool cmp(int a,int b){
	return a > b;
}
int32_t main(){
	
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>s;
    int l = s.size();
    int j=0;
    for(int i=0; i<l; i++)
    	if('0'<=s[i]&&s[i]<='9'){
    		num[j]=s[i]-'0';
    		j++;
		}
	sort(num,num+j,cmp);
	for(int i=0;i<j;i++) cout<<num[i];
 	return 0;
}
