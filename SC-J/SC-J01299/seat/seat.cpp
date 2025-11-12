#include<bits/stdc++.h>
#define len n*m
using namespace std;
int n,m,a[122],a1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=len;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+len+1,cmp);
	int i=1,j=1,s=1;
	while(1){
		if(a[s]==a1) break;
		if(i%2==1){
			if(j<n) j++;
			else i++;
		}
		else{
			if(j>1) j--;
			else i++;
		}
		s++;
	}
	cout<<i<<' '<<j<<endl;
	return 0;
}