#include<bits/stdc++.h>
using namespace std;
const int Maxn=1001000;
int a[Maxn],j=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    char s[Maxn];
    cin >> s;
    int f = strlen(s);
    
    for(long long i=0;i<f;i++){
    	if('0'<=s[i]&&s[i]<='9'){
    		a[j] = s[i]-'0';
    		j++;
		}
	}
    sort(a,a+j,cmp);
    for(long long i=0;i<j;i++) cout << a[i];
    
	return 0;
}
