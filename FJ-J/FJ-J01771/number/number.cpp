#include<bits/stdc++.h> //I wanna AK IOI
using namespace std;
char ch;
char a[1000005];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while((ch=getchar())&&ch!='\n'&&ch!=EOF){
		if(isdigit(ch)) a[++cnt]=ch;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--) putchar(a[i]);
	return 0;
}
