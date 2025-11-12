#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int h[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			h[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=h[i];j++)printf("%d",i);
	}
	return 0;
}
/*
8:30 了但是没有下发试题册，略微吐槽一下 
8:32 下发了试题册，然而并没有 change，怎么 LA 群里篮球不太准

T1旨在考验选手字符串水平，说白了水题。 
*/ 