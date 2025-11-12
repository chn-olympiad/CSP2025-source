#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string a;
	int b[1145141]={0};
	int n=0,t=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1' or a[i]=='2' or a[i]=='3' or a[i]=='4' or a[i]=='5' or a[i]=='6' or a[i]=='7' or a[i]=='8' or a[i]=='9'){
			 b[t]+=a[i];
			 b[t]-=48;
			 t++;
		}
		if(a[i]=='0') n++;
	}
	sort(b,b+t,cmp);
	for(int i=0;i<t;i++) printf("%d",b[i]);
	for(int i=0;i<n;i++) printf("0");
	return 0;
}
