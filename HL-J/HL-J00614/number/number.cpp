#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,num=1,b[100];
	cin>>a;
	if(a<10)
		cout<<a;
	else if(a>=10 && a<100){
		int c=a%10;
		int d=a/10%10;
		if(c<d)
			cout<<a;
		else 
			cout<<c<<d;
	}
	else if(a>=100){
	for(int i=1;i;i++){
		if(a<=9)
			break;
		else{
			for(int i=num;i<=num+1;i++){
				b[i]=a%10;
			}
			a/10;
			num++;
		}
	}
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num;j++){
			if(b[i]>10)
				continue;
			else if(b[i]<b[j])
				swap(b[i],b[j]);
		}
	for(int i=1;i<=num;i++)
		cout<<b[i];
	}
}
	return 0;
}
