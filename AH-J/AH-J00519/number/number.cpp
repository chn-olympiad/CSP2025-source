#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
char s[1000005];
long long n,a[1000005],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;


	if(s[0]>='0'&&s[0]<='9'){
        a[k]=s[0]-'0';
        k++;
	}

	for(int i=1;i<1000005;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }

	}
	sort(a+0,a+k+1,cmp);
	for(int i=0;i<k-1;i++){
		cout<<a[i];
	};


	return 0;
}
