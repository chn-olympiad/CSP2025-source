#include<bits/stdc++.h>
using namespace std;
char a[100006];
long long n[100006],m;
int main(){
    scanf("%s",a+1);
    for(int i=1;;i++){
		if(a[i]==0){
			m=i;
			break;
		}
	}
    for(int i=1;i<=m;i++) n[i]=a[i]-'0';
    for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(n[j]<n[j+1]&&n[j]<10&&n[j+1]<10){
				int t=n[j];
				n[j]=n[j+1];
				n[j+1]=t;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(n[i]<10) cout<<n[i];
		else break;
	}
    return 0;
}
