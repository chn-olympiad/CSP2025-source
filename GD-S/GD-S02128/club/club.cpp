#include<bits/stdc++.h> 
using namespace std;
int b[501],l[501],c[501],y[501],ch[501],n,m,u;
char a[501];
int lie(int h,int pe){
if(h==strlen(a)+1&&pe>=m){
u++;
}
else{
for(int i=1;i<=n;i++){
if(!l[i]){
y[h]=i;
if(ch[h-1]>=c[h]){
pe--;	
}
ch[h]+=ch[h-1];
if(b[h]==0){
ch[h]++;
}
l[i]=1;
lie(h+1,pe);
ch[h]=ch[h]-ch[h-1];
if(b[h]==0){
ch[h]--;
}
y[h]=0;
l[i]=0;
}	
}
}	
	
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ","w",stdout);
cin>>n>>m;
gets(a);
for(int i=1;i<=strlen(a);i++){
b[i]=a[i]-'0';
}
lie(1,n);
cout<<u;

fclose(stdin);
fclose(stdout);	
return 0;
}

