#include<bits/stdc++.h>
using namespace std;
int a[105]={0},n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("poker.in","r",stdin);
	feropen("poker.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];

	int b=a[0];
sort(a,n*m+a,cmp);
int i=0;
while(b!=a[i])i++;
int o=i/m,p=i%m;
if(o%2==0){
	if(p)cout<<n-p<<' '<<o+1+(o+1);
}	else{
		if(p)cout<<n-o+1<<" "<<o+1;
	}

    return 0;

}
