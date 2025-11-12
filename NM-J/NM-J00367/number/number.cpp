#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005],x;
int cmp(int b,int y){
 return b>y;
}
int main(){
 int i=1;
 while(x){
  cin>>x;
  if(x=='0'||x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'){c[i]=x;i++;}
 }
 for(int j=1;j<=i;j++){
	 a[j]=c[j];
	 }
 sort(a+1,a+i+1,cmp);
 for(int j=1;j<=i;j++){
  cout<<a[i];
 }
 return 0;

}
