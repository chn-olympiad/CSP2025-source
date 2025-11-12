#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int lena,now=1,num[1000001];
    char a[1000001];
    cin>>a;
    lena=strlen(a);
    for(int i=0;i<lena;i++){
    	if(a[i]-'0'>=0 && a[i]-'0'<=9){
    		num[now]=a[i]-'0';
    		now++;
		}
	}
	sort(num+1,num+1+now,cmp);
	for(int i=1;i<now;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
