#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
bool cmp(int a,int b){
    return a>b;	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char s;
    long long e=0,f=0;
    while(cin>>s){
		if(s>='0'&&s<='9'){
			a[e]=s-'0';
			e++;
			f++;
		}
	}
	sort(a,a+f,cmp);
	for(long long i=0;i<f;i++){
		cout<<a[i];
	}
    return 0;
}
