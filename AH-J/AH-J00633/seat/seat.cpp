#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int s[110],p[110];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int l=n*m;
for(int i=1;i<=l;i++)cin>>s[i];
int r=s[1];
sort(s+1,s+1+l);
int o=0;
for(int i=l;i>=1;i--){
	o++;
	p[o]=s[i];
}
for(int i=1;i<=o;i++)s[i]=p[i];
int ans;
for(int i=1;i<=l;i++){
	if(s[i]==r)ans=i;
}
int i=1,j=1,f=0,t=1;
if(ans==1){
	cout<<1<<' '<<1;
	return 0;
}
while(l--){
	t++;
	if(!f){
		if(i==n){
			j++;
			f=1;
		}
		else i++;
	}
	else{
		if(i==1){
			j++;
			f=0;
		}
		else i--;
	}
	if(t==ans)cout<<j<<' '<<i;
}
return 0;
}
