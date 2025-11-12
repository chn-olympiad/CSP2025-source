#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],a1,r[110];
void px(int s,int e){
	if(s==e) return ;
	int mid=(s+e)/2,d=1,i=s,j=mid+1;
	px(s,mid);
	px(mid+1,e);
	
	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			r[d++]=a[i++];
		}
		else{
			r[d++]=a[j++];
		}
	}
	while(i<=mid){
		r[d++]=a[i++];
	}
	while(j<=e){
		r[d++]=a[j++];
	}
	d=1;
	for(int i=s;i<=e;i++) a[i]=r[d++];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	px(1,n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1){
			int b=(n*m-i+1)/n,d=(n*m-i+1)%n;
			if(d==0) cout<<b<<' ';
			else cout<<++b<<' ';
			int c=b%2;
			if(c){
				if(d==0) cout<<n;
				else cout<<d;
			}
			else cout<<n-d+1;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

