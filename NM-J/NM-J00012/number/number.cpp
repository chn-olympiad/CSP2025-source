#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000005],cnt=0;
    char n;
    while(cin>>n){
        if(n>='0'&&n<='9')a[++cnt]=(n-'0');
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
    return 0;
}
/*
 * 约100+100+40+40=280吧
	最低……，不知道……
	燃尽了……
	qwq
	AK,IOI!!
	while(1) rp++;
*/
