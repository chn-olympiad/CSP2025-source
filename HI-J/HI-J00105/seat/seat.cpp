#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int a,b;
cin>>a>>b;
int s[a*b+5];
for(int i=1;i<=a*b;i++)s[i]=101;
for(int i=1;i<=a*b;i++)cin>>s[i];
int k_=-1,k=s[1];
sort(s+1,s+a*b+1);
int fo=1;
for(int i=a*b;i>=1;i--){
	if(s[i]==k){
	break;
	}
	fo++;
	
}
if(a==1)
{
	cout<<1<<" "<<fo;
	return 0;
}
if(fo%a==0){
	cout<<fo/a<<" "<<a;
	return 0;
}
if(fo%a>0){
	cout<<fo/a+1<<" "<<fo%a;
	return 0;
}
cout<<fo/a<<" "<<fo%a;
return 0; 
fclose(stdin);
fclose(stdout);

}
