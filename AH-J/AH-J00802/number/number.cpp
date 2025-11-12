#include<bits/stdc++.h>
using namespace std;
int b[1000010],cnt;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;i++){
	int t=a[i];
	    if(t>='0'&&t<='9'){
		b[++cnt]=(t-'0');
	    }
    }
    sort(b+1,b+cnt+1);
    for(int i=cnt;i>=1;i--){
	cout<<b[i];
    }
    return 0;
}

