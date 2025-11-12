#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,b;
bool cmp(int az,int aq){
	return az>aq;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			b=i+1;
			break;
		}
	}
	cout<<ceil(b*1.0/n)<<" ";
	int p=b%n;
	int c=ceil(b*1.0/n);
	if(c%2==1){
		if(p==0) cout<<n;
		else cout<<p<<endl;
	}
	else{
		if(p==0) cout<<1<<endl;
		else cout<<n-p+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
