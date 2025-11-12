#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _sg string
ll rd(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}

ll n,m;
ll a[500];
ll s[100][100];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n*m;i++)
    	a[i]=rd();
    ll rs=a[1];
	sort(a+1,a+1+n*m,cmp);
	int now=1,i=1,j=1;
	while(1){
		if(a[now]==rs){
			cout<<abs(i)<<' '<<j;
			return 0;
		}
		now++;
		if(i>0){
			if(j<n)j++;
			else{
				j=n;
				i++;i=-i;
			}
		}
		else{
			if(j==1){
				j=1;
				i=-i;i++;
			}else j--;
		}
	}	
	return 0;
}
