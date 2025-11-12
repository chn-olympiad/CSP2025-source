#include<bits/stdc++.h>
using namespace std;
int a[10000005];
char c[10000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0;
    cin>>c;
    for(int i=0;i<int(strlen(c));i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[++n]=c[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		printf("%d",a[i]);
    return 0;
}
