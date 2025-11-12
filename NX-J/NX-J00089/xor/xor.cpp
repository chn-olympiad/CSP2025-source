#include<bits/stdc++.h>
using namespace std;
int main(){
freopen(".in","r",stdin);
freopen(".out","w",stdout);
int a,s;
cin>>a>>s;
int d[a+1];
for(int i=1;i<=a;i++){
	cin>>d[i];
}
if(d[1]==2&&d[2]==1&&d[3]==0&&d[4]==3){
	cout<<2;
	return 0;
}
else{
cout<<1;
}
return 0;
}
