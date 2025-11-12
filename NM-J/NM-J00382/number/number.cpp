#include <bits/stdc++.h>
using namespace std;
int t[10010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int i,j,s;
cin>>s;
for(i=1;i<=100;i++){
	t[i]=s%10;
	s=s/10;
}for(i=1;i<=100;i++){
	for(j=1;j<=s;j++){
	if(t[i]<t[i+1]){
	swap(t[i],t[i+1]);
	}
	}
}for(i=1;i<=s;i++){
	cout<<t[i];
}
}
