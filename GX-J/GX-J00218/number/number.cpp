#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    long long tmp=0,sum=0;
    cin>>s;
    for(auto i:s){
		if(i-'0'>=0&&i-'0'<=9){
			sum++;
		}
	}
	int a[sum+10];
    for(auto i:s){
		if(i-'0'>=0&&i-'0'<=9){
			a[tmp]=i-'0';
			tmp++;
		}
	}
	sort(a,a+sum+2);
	for(int i=sum;i>=1;i--){
		cout<<a[i];
	}
    return 0;
}
