#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000010];
int k;
int main(){
    string ss;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	for(LL i=0;i<ss.size();i++){
        if(ss[i]>='0'&&ss[i]<='9'){
            k++;
            a[k]=ss[i]-'0';
        }
	}
	sort(a+1,a+1+k);
	for(LL i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
