#include <bits/stdc++.h>
using namespace std;
string a;
int i=1,c,n=0,j=0;
int num[101],wbqaityy[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(i!=0){
		i=a[j];
		num[j]=i;
		j++;
	}
	for(int y=0;y<j;y++){
		if(num[y]>=48 and num[y]<=57){
			c=num[y]-48;
			wbqaityy[n]=c;
			n++; 
		}else{
			y+=0;
		}
	}
	sort(wbqaityy,wbqaityy+n);
	for(int i=n-1;i>=0;i--){
		cout<<wbqaityy[i];
	}
	return 0;
}
