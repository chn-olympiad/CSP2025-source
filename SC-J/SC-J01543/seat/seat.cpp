#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],sz,pos; 
int cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	sz=a[1];
	//cout<<sz<<endl;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<" ";
		if(sz==a[i]){
			pos=i;
		}
	}
	//cout<<endl;
	//cout<<pos<<endl;
	int l=pos/n;
	if(pos%n!=0){
		l++;
	}
	cout<<l<<" ";//列
	if((l)%2==1){
		cout<<(pos-1)%n+1;
	}else{
		cout<<n+1-((pos-1)%n+1);
	}
	//a1,a2,...,an*m互不相同。
	return 0;
}